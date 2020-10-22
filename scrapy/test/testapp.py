url='https://app3.abc-mart.net/svc/mailLink/Login/?token=99c2ace05c6504fa349a0459b530ecd8'
import sys
sys.path.append('..')
from abcmart import abcmart


site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
 

'''
POST https://app3.abc-mart.net/nativeAppApi/common/DeviceTokenAdd/ HTTP/1.1
'''
'''
'Host': 'app3.abc-mart.net',
'Accept': '*/*'
Authorization: Basic YXBwMzA6YWJjbWFydGFwcA==
App-Version: 3.5.2
Accept-Encoding: gzip;q=1.0, compress;q=0.5
OS: iOS 14.0.1
Accept-Language: zh-Hans-CN;q=1.0, en-CN;q=0.9, zh-Hant-CN;q=0.8
Content-Type: application/json
Content-Length: 301
User-Agent: ABC-MART APP
Connection: keep-alive
'''

'''
{"idToken":"a52c9f173a951a30800e200f1706312f64d7aa5737274175bef44abd87740ce8"}
{"deviceToken":"f208030061b3b3d17201e33b298fcfe3984b4e563e4b45c0150a9b4ea1fd0257","idToken":"a52c9f173a951a30800e200f1706312f64d7aa5737274175bef44abd87740ce8","deviceId":"f0fb248de9b2902e43117b044e14cdd2663f19ce57928eb2186c8d2143ac222ec57a3e319348e26333ed61db502cffa1b82aab85a7a4a590356bd20cab3a3096"}
'''

'''
POST https://app3.abc-mart.net/nativeAppApi/cart/CartUpdate/ HTTP/1.1
Host: app3.abc-mart.net
Accept: */*
Authorization: Basic YXBwMzA6YWJjbWFydGFwcA==
App-Version: 3.5.2
Accept-Encoding: gzip;q=1.0, compress;q=0.5
OS: iOS 14.0.1
Accept-Language: zh-Hans-CN;q=1.0, en-CN;q=0.9, zh-Hant-CN;q=0.8
Content-Type: application/json
Content-Length: 122
User-Agent: ABC-MART APP
Connection: keep-alive
Cookie: __utmmobile=0x737ec76b163ac71a; abc-mart_acquisition=1; d_abc-mart_service_sid_3gen=31361207b64585c761ea2606fc827558; abc-mart_guest=1; x-vckey=b953b29a6fb3dc006fb089512227b3144e6c3d7f
paydata = {"idToken":"a52c9f173a951a30800e200f1706312f64d7aa5737274175bef44abd87740ce8","product_code":"5972670004082","quantity":1}
'''
header={'Host': 'app3.abc-mart.net',
'Accept': '*/*',
'App-Version': '3.5.2',
'Accept-Encoding': 'gzip;q=1.0, compress;q=0.5',
'OS': 'iOS 14.0.1',
'Accept-Language': 'zh-Hans-CN;q=1.0, en-CN;q=0.9, zh-Hant-CN;q=0.8',
'Content-Type': 'application/json',
'Content-Length': '122',
'User-Agent': 'ABC-MART APP',
'Connection': 'keep-alive'}
{"idToken":"a52c9f173a951a30800e200f1706312f64d7aa5737274175bef44abd87740ce8"}
device={"deviceToken":"f208030061b3b3d17201e33b298fcfe3984b4e563e4b45c0150a9b4ea1fd0257","idToken":"a52c9f173a951a30800e200f1706312f64d7aa5737274175bef44abd87740ce8","deviceId":"f0fb248de9b2902e43117b044e14cdd2663f19ce57928eb2186c8d2143ac222ec57a3e319348e26333ed61db502cffa1b82aab85a7a4a590356bd20cab3a3096"}



'''
POST https://app3.abc-mart.net/nativeAppApi/common/Init/ HTTP/1.1
Host: app3.abc-mart.net
OS: iOS 14.0.1
Content-Type: application/json
Accept: */*
Content-Length: 0
Connection: keep-alive
Accept-Language: zh-Hans-CN;q=1.0, en-CN;q=0.9, zh-Hant-CN;q=0.8
User-Agent: ABC-MART APP
Authorization: Basic YXBwMzA6YWJjbWFydGFwcA==
App-Version: 3.5.2
Accept-Encoding: gzip;q=1.0, compress;q=0.5
'''
'''{"status":200,"appVersion":"3.2.0","serverTime":"2020-10-22 17:30:27","data":{"deviceId":"36f563facdfcee46af0c8284c806b5957863b9f8ff830a972088032b785fa34ce7483b74fe598e04aa30948ee51ff459b0d123dd1f8cb299aac6179e6939769c"},"errorType":0}'''

initurl ='https://app3.abc-mart.net/nativeAppApi/common/Init/'
header = {
    'Host': 'app3.abc-mart.net',
'OS': 'iOS 14.0.1',
'Content-Type': 'application/json',
'Accept': '*/*',
'Content-Length': '0',
'Connection': 'keep-alive',
'Accept-Language': 'zh-Hans-CN;q=1.0, en-CN;q=0.9, zh-Hant-CN;q=0.8',
'User-Agent': 'ABC-MART APP',
'Authorization': 'Basic YXBwMzA6YWJjbWFydGFwcA==',
'App-Version': '3.5.2',
'authority': 'www.abc-mart.net',
#'scheme': 'https',
'Accept-Encoding': 'gzip;q=1.0, compress;q=0.5'
}
paydata = {"idToken":"a52c9f173a951a30800e200f1706312f64d7aa5737274175bef44abd87740ce8","product_code":"5972670004082","quantity":1}
site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
# import ssl 
# ssl._create_default_https_context = ssl._create_unverified_context
site.page.setHeaders(header)
pd = 'https://app3.abc-mart.net/nativeAppApi/product/GetProductData/'
paydata = {"sku_code":"6081370005049","idToken":"d7fde4d880bad170710d4ce8afcb656100313cbe97e7cd7b68205f4509ac5926"}


resp=site.page.post(pd,paydata)
print(resp.text)
 