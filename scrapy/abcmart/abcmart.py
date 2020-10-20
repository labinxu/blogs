from common import site
from . import abcpage
class AbcMart(site.Site):
    def __init__(self,sitename,url):
        super().__init__(sitename,url)
        self.carturl='https://www.abc-mart.net/shop/g/%s'

        self.page=abcpage.AbcMartPage()

        header={'authority': 'www.abc-mart.net',
                'method': 'GET',
                'path': '/shop/customer/menu.aspx',
                'scheme': 'https',
                'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
                'accept-encoding': 'gzip, deflate, br',
                'accept-language': 'zh-CN,zh;q=0.9',
                'referer': 'https://www.abc-mart.net/shop/customer/logout.aspx',
                'sec-fetch-dest': 'document',
                'sec-fetch-mode': 'navigate',
                'sec-fetch-site': 'same-origin',
                'sec-fetch-user': '?1',
                'upgrade-insecure-requests': '1'}
        self.page.updateHeaders(header)

    def login(self,username,passwd):
        '''
:method: POST
:path: /shop/customer/menu.aspx
:scheme: https
accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
accept-encoding: gzip, deflate, br
accept-language: zh-CN,zh;q=0.9
cache-control: max-age=0
content-length: 45
content-type: application/x-www-form-urlencoded
cookie: netmart98Shop=Session=981727731&Key=9cc99ca58bb9a75cccd82c35b634c283; __sna_s1d=CLhcQQMleFtr3CzWbu2CMlM0Pvj4m8; FormAssist_1tag=view; tuuid=40d24aa4-e493-45b8-b604-e9a2501414fb; _gcl_au=1.1.1746267344.1603208867; _ga=GA1.2.273471939.1603208867; _gid=GA1.2.679237898.1603208867; FormAssist_cookie=abcm/20200508165456/20201021/004747-294; _fbp=fb.1.1603208870161.674374247; snexid=1a6827ab-51a4-46ff-819b-eb3faadd016b; ASP.NET_SessionId=zafsftjgjdqtmd1n4fwhrile; netmart98Shop_agent=012000000000w0n0y600lfnqd5x08000000i0000000x0040x0r009a00th000r0; npuip=9e9c9f78-4210-45e2-a720-f376d1052598; _ts_yjad=1603209072539; _a1_f=795f05f2-1af5-4c5b-a838-cfc58e9cf957; _a1_u=40d24aa4-e493-45b8-b604-e9a2501414fb; netmart98Shop_ReturnUrl=login=%2fshop%2fcustomer%2fmenu.aspx; netmart98Shop_secure=SecureKey=; _gat_UA-7317182-2=1
origin: https://www.abc-mart.net
referer: https://www.abc-mart.net/shop/customer/menu.aspx
sec-fetch-dest: document
sec-fetch-mode: navigate
sec-fetch-site: same-origin
sec-fetch-user: ?1
upgrade-insecure-requests: 1
user-agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.80 Safari/537.36'''
        paydata = { 'uid': username,
                     'pwd': passwd,
                     'loginstatesaving': 'true'}
        
        loginurl='https://www.abc-mart.net/shop/customer/menu.aspx'#'https://www.abc-mart.net/shop/customer/menu.aspx?site=g'
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