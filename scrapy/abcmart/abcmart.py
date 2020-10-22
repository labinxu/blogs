from common import site
from . import abcpage
import logging,random
import requests,json
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)
# logger.setLevel(logging.INFO) 

class AbcMart(site.Site):
    def __init__(self,sitename,url):
        super().__init__(sitename,url)
        self.page=abcpage.AbcMartPage()

        header={'authority': 'www.abc-mart.net',
                'scheme': 'https',
                'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
                'accept-encoding': 'gzip, deflate, br',
                'accept-language': 'zh-CN,zh;q=0.9',
                'user-agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Safari/537.36'
                }
        self.page.updateHeaders(header)

    def login(self,username,passwd):
        #visit shop page
        shop = 'https://www.abc-mart.net/shop/'
        self.page.get(shop)
        # visit login page
        header  = {
                'method': 'POST',
                'path': '/shop/customer/menu.aspx',
                'content-type': 'application/x-www-form-urlencoded',
                'origin': 'https://www.abc-mart.net',
                'referer': 'https://www.abc-mart.net/shop/customer/menu.aspx',
                'upgrade-insecure-requests': '1'}
        self.page.updateHeaders(header)
        paydata = { 'uid': username,
                     'pwd': passwd,
                     'loginstatesaving': 'true'}
        self.page.makeAuth(username,passwd)
        loginurl='https://www.abc-mart.net/shop/customer/menu.aspx' 
        return self.page.login(loginurl,paydata)

    def listgoods(self,arturl):        
        soup = self.page.getSoup(arturl)
        sizelistTag = soup.find('div',attrs={'class':'choosed_size_list'})
        listdata =[]
        for li in sizelistTag.findAll('li'):
            if not li:
                continue
            size = li.find('strong')
            listdata.append(size.text.strip())
            # statusTag=dl.find('a')#,attrs={'class':'ajax_cartbtn_'})
            # if not statusTag:
            #     continue

            # #size 
            # sizeTag = dl.find('dt')
            # if not sizeTag:
            #     continue
            # listdata.append((sizeTag.text.split(' ')[0],statusTag['href']))
        
        return listdata
    def getProductData(self,gcode,token):
        header = {
            'Host': 'app3.abc-mart.net',
            'OS': 'iOS 14.0.1',
            'Content-Type': 'application/json',
            'Connection': 'keep-alive',
            'Accept-Language': 'zh-Hans-CN;q=1.0, en-CN;q=0.9, zh-Hant-CN;q=0.8',
            'User-Agent': 'ABC-MART APP',
            'App-Version': '3.5.2',
         }
        productUrl = 'https://app3.abc-mart.net/nativeAppApi/product/GetProductData/'
        paydata = '{"sku_code":"%s","idToken":"%s"}'%(gcode,token)
        logger.debug(paydata)
        resp=requests.post(productUrl,data=paydata,headers=header,verify=False)
        jsonobj = json.loads(resp.text)
        productData={}
        for p in jsonobj['data']['product']['size']:
            productData[p['name']]=p['sku_code']
        return productData

    def submitOrder(self):

        orderurl = 'https://www.abc-mart.net/shop/order/method.aspx'
        resp = self.page.getSoup(orderurl)
        #check status
        submitTag = resp.find('input',attrs={'name':'submit','class':'confirmation_btn','id':'FormAssist_submit'}) 
        if not submitTag:
            logger.error("page is invalied")
            return
        # post data
        paydata = {
            'mode':'',
            'dest1':'0',
            'dest_no':'0',
            'coupon':'',
            'method':'2',
            'giftcardnum':'',
            'reference.x':'true',
            'pin':'',
            'giftpay': '0',
            'giftprice':'', 
            'refresh': 'true',
            'submit.x':random.randint(0,200),
            'submit.y':random.randint(0,100)
        }
        
        cartlistTag = resp.find('table',attrs={'class':"formlist_ cartlist_"})
        if cartlistTag:
            trTags = cartlistTag.findAll('tr')
            for trTag in trTags:
                #tdtag = trTag.find('td',attrs={'class':'img_'})
                inputTags = trTag.findAll({'input','select'})
                for inputTag in inputTags:
                    try:
                        paydata[inputTag['name']]=inputTag['value']
                    except Exception as identifier:
                        paydata[inputTag['name']]='0'
                        logger.info(inputTag['name']+"error")
        else:
            logger.error('no cart list found!')
            return
        
        # submit the order step2
        resp = self.page.postSoup(orderurl,paydata)
        inputTags = resp.findAll('input',attrs={'type':"hidden"})
        # step 3
        paydata={}
        if inputTags:
            for inputTag in inputTags:
                try:
                    paydata[inputTag['name']]=inputTag['value']
                except Exception as identifier:
                    logger.info("error"+inputTag['name'])
                    paydata[inputTag['name']]='0'
        estimateurl='https://www.abc-mart.net/shop/order/estimate.aspx?'
        logger.debug(paydata)
        # TODO:post the data
        headers={'Content-Type': 'application/x-www-form-urlencoded'}
        self.page.updateHeaders(headers)
        data='estimate=%s&gc=&p=&comment=&submit.x=%s&submit.y=%s'%(paydata['estimate'],random.randint(0,200),random.randint(0,100))

        resp = self.page.postSoup(estimateurl,data)
        ret = resp.find('a')
        logger.debug(ret.text)

    def addCart(self, gcode):

        #https://www.abc-mart.net/shop/g/g6025230001012/
        carturltmp='https://gs.abc-mart.net/shop/g/g%s'
        #list the goods
        goods = self.listgoods(carturltmp%gcode)
        logger.debug(goods)
        addurl  = 'https://www.abc-mart.net/shop/cart/cart.aspx?goods=%s'%gcode
        self.page.getSoup(addurl)
        
        return
        # postdata = {"goods": gcode,"ds_warehouse":""} 
        # headers = {"authority":"www.abc-mart.net",
        #              "method":"POST",
        #              "path":"/shop/cart/cartaddajax.aspx/",
        #              "scheme":"https",
        #              "accept":"*/*",
        #              "accept-encoding":"gzip, deflate, br",
        #              "accept-language":"en-US,en;q=0.9,zh-CN;q=0.8,zh;q=0.7,fr;q=0.6,ja;q=0.5",
        #              "content-length":"33",
        #              "content-type":"application/x-www-form-urlencoded; charset=UTF-8",
        #              "origin":"https://www.abc-mart.net",
        #              "referer":"https://www.abc-mart.net/shop/g/"+gcode+'/',
        #              "x-requested-with":"XMLHttpRequest"}
        # self.page.updateHeaders(headers)
        # resp = self.page.postSoup(addurl, postdata)
        # #import pdb;pdb.set_trace()
        # #check add successful
        # carturl='https://www.abc-mart.net/shop/cart/cart.aspx'
        