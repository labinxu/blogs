from abcmart import abcmart
import sys

import requests
if __name__=='__main__':
    header = {
        'Host': 'app3.abc-mart.net',
    'OS': 'iOS 14.0.1',
    'Content-Type': 'application/json',
    'Connection': 'keep-alive',
    'Accept-Language': 'zh-Hans-CN;q=1.0, en-CN;q=0.9, zh-Hant-CN;q=0.8',
    'User-Agent': 'ABC-MART APP',
    'App-Version': '3.5.2',
    }
    paydata = '{"idToken":"a52c9f173a951a30800e200f1706312f64d7aa5737274175bef44abd87740ce8","product_code":"5972670004082","quantity":1}'
    pd = 'https://app3.abc-mart.net/nativeAppApi/product/GetProductData/'
    paydata = '{"sku_code":"6081370005049","idToken":"d7fde4d880bad170710d4ce8afcb656100313cbe97e7cd7b68205f4509ac5926"}'

    resp=requests.post(pd,data=paydata,headers=header,verify=False,proxies={"http":"192.168.2.179:8866"})
    #resp=site.page.post(pd,paydata)
    print(resp.text)