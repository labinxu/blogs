from common import site
from . import abcpage
class AbcMart(site.Site):
    def __init__(self,sitename,url):
        super().__init__(sitename,url)
        self.carturl='https://www.abc-mart.net/shop/g/%s'

    def login(self,username,passwd):
        paydata = { 'uid': username,
                     'pwd': passwd,
                     'loginstatesaving': 'true'}
        self.page=abcpage.AbcMartPage()
        loginurl='https://www.abc-mart.net/shop/customer/menu.aspx?site=g'
        status,resp = self.page.login(loginurl,paydata)

    def listgoods(self,gcode):
        arturl=self.carturl%gcode
        soup = self.page.getsoup(arturl)
        sizelistTag = soup.find('div',attrs={'class':'choosed_size_list'})
        listdata =[]
        for dl in sizelistTag.findAll('dl'):
            if not dl:
                continue
            statusTag=dl.find('a',attrs={'class':'ajax_cartbtn_'})
            if not statusTag:
                continue

            #size 
            sizeTag = dl.find('dt')
            if not sizeTag:
                continue
            listdata.append((sizeTag.text.split(' ')[0],statusTag['href']))
        
        return listdata
                
    def addcart(self, gcode, size=0):
        #https://www.abc-mart.net/shop/g/g5987070004013/
        #arturl=self.carturl%gcode
        #find the goods
        #goods = listgoods(gcode)
        #add
        #import pdb ;pdb.set_trace()
        addurl  = 'https://www.abc-mart.net/shop/cart/cartaddajax.aspx'
        postdata = {"goods": gcode,"ds_warehouse":""} 
        headers = {#":authority":"www.abc-mart.net",
                    #":method":"POST",
                    #":path":"/shop/cart/cartaddajax.aspx/",
                    #":scheme":"https",
                    "accept":"*/*",
                    "accept-encoding":"gzip, deflate, br",
                    "accept-language":"en-US,en;q=0.9,zh-CN;q=0.8,zh;q=0.7,fr;q=0.6,ja;q=0.5",
                    "content-length":"33",
                    "content-type":"application/x-www-form-urlencoded; charset=UTF-8",
                    "origin":"https://www.abc-mart.net",
                    "referer":"https://www.abc-mart.net/shop/g/g5977470001013/",
                    "x-requested-with":"XMLHttpRequest"}
        self.page.addHeaders(headers)
        resp = self.page.post(addurl, postdata)
        #check add successful
        #'https://www.abc-mart.net/shop/cart/cart.aspx'
        resp = self.page.get('https://www.abc-mart.net/shop/js/cart.aspx')
        print(resp)