import requests
from requests.auth import HTTPBasicAuth 
from requests.auth import HTTPDigestAuth
#url = 'https://httpbin.org/digest-auth/auth/user/pass'
#requests.get(url, auth=HTTPDigestAuth('user', 'pass'))
header={
    'Host': 'app3.abc-mart.net',
    'Accept': '*/*',
'App-Version': '3.5.2',
'Accept-Encoding': 'gzip;q=1.0, compress;q=0.5',
'OS': 'iOS 14.0.1',
'Accept-Language': 'zh-Hans-CN;q=1.0, en-CN;q=0.9, zh-Hant-CN;q=0.8',
'Content-Type': 'application/json',
'Content-Length': '105',
'User-Agent': 'ABC-MART APP',
'Authorization': 'Basic YXBwMzA6YWJjbWFydGFwcA==',
'Connection': 'keep-alive'}
pd = 'https://app3.abc-mart.net/nativeAppApi/product/GetProductData/'
paydata = {"sku_code":"6081370005049","idToken":"d7fde4d880bad170710d4ce8afcb656100313cbe97e7cd7b68205f4509ac5926"}
response = requests.post(pd,headers=header,verify=False,data=paydata)
print(response.text)

 