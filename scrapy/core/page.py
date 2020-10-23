import requests
import platform,os
from . import logmanager

logger = logmanager.LogManager().getLogger()

if platform.system() == 'Windows':
    try:
        from requests_ntlm import HttpNtlmAuth
        from requests_kerberos import HTTPKerberosAuth, REQUIRED
    except Exception as e:
        pass

from bs4 import BeautifulSoup

# disable the ssl warnings
from requests.packages import urllib3
urllib3.disable_warnings()

class Page():
    def __init__(self, domain=''):
        """
        @param: content web page content
        @param: htmlparser web page parser HTMLParser or bs4.BeautifulSoup
        """
        self.domain = domain
        self.session = requests.Session()
        header = {'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36'}
        self.session.headers.update(header)
        self.auth = None
        self.status_code = None
        self.respHeader = None
        self.cookies={}
        self.res_cookies_txt=''
        self.proxies = {}

    def setProxies(self,proxies):
        self.proxies = proxies

    def updateHeaders(self, headers):
        self.session.headers.update(headers)

    def activeCookie(self,cookiename):
        ckpath = cookiename
        if not os.path.exists(ckpath):
            logger.info("%s not exist"%ckpath)
            return False

        with open(ckpath,'r',encoding='utf-8') as f:
            cookies_txt = f.read().strip(';')
            for cookie in cookies_txt.split(';'):
                name,value=cookie.strip().split('=',1)
                self.cookies[name]=value
        #将字典转为CookieJar：
        self.session.cookies=requests.utils.cookiejar_from_dict(self.cookies,
                                                                cookiejar=None,overwrite=True)
        return True
    
    def storeCookie(self,cookiename):
        res_cookies_dic = requests.utils.dict_from_cookiejar(self.session.cookies)
        for i in res_cookies_dic.keys():
            self.cookies[i] = res_cookies_dic[i]
        for k in self.cookies.keys():
            self.res_cookies_txt += k+"="+self.cookies[k]+";"
        with open(cookiename,'w',encoding="utf-8") as f:
            f.write(self.res_cookies_txt)

    def setHeaders(self, headers):
        self.session.headers = headers

    def makeNtlmAuth(self, username, password):
        logger.debug('[+] Make HttpNtlmAuth %s' % username)
        auth = HttpNtlmAuth('%s\\%s' % (self.domain, username),
                            password, self.session)

        self.auth = auth

    def makeKerberosAuth(self):
        auth = HTTPKerberosAuth(mutual_authentication=REQUIRED,
                                sanitize_mutual_error_response=False)
        self.auth = auth

    def makeAuth(self, username, password):
        self.auth = (username, password)

    def get(self, url,**kwargs):
        logger.debug('[+] Get: %s' % url)
        response = self.session.get(url, auth=self.auth, verify=False, proxies=self.proxies)
        self.status_code = response.status_code
        return response

    def getSoup(self, url):
        r = self.get(url)
        self.respHeader=r.headers
        return BeautifulSoup(r.text.encode('utf-8'), 'html.parser')

    def post(self, url, data, **kwargs):
        logger.debug('[+] Post %s with data:%s' % (url,data))
        return  self.session.post(url, data=data, proxies=self.proxies)

    def getRespHeaders(self):
        return self.respHeader

    def postSoup(self, url, data):
        r = self.post(url, data=data)
        return BeautifulSoup(r.text.encode('utf-8'), 'html.parser')

###################################################################

def ReadFileAsContent(filename):
    #print filename
    try:
        with open(filename, 'rb') as f:
            filecontent = f.read()
    except Exception as e:
        logger.error(str(e))
        return ''
    return filecontent

def get_content_type(filename=None):
  import mimetypes
  if filename:
      return mimetypes.guess_type(filename)[0] or 'application/octet-stream'
  else:
      return 'application/octet-stream'

def isfiledata(p_str):
    import re
    r_c = re.compile("^f'(.*)'$")
    rert = r_c.search(str(p_str))
    #/home/laxxu/BSAok.csv
    #rert = re.search("^f'(.*)'$", p_str)
    if rert:
        return rert.group(1)
    else:
        return None

def encode_multipart_formdata(fields):
    '''
    '''
    import random
    import os
    BOUNDARY = '%s%s' % ('-'*29 ,''.join(random.sample('01234567890123456789', 13)))
    CRLF = '\r\n'
    L = []
    # import pdb;pdb.set_trace()
    for (key, value) in fields:
        filepath = ''
        if (value and os.path.exists(value) and os.path.isfile(value)):
            filepath = value

        #filepath = isfiledata(value)
        if filepath:
            L.append('--' + BOUNDARY)
            L.append('Content-Disposition: form-data; name="%s"; filename="%s"' % (key, os.path.basename(filepath)))
            L.append('Content-Type: %s' % get_content_type(filepath))
            L.append('')
            L.append(ReadFileAsContent(filepath))
        elif 'file' in key:
            L.append('--' + BOUNDARY)
            L.append('Content-Disposition: form-data; name="%s"; filename=""' % key)
            L.append('Content-Type: %s' % get_content_type())
            L.append('')
        else:
            L.append('--' + BOUNDARY)
            L.append('Content-Disposition: form-data; name="%s"' % key)
            L.append('')
            L.append(value)
    L.append('--' + BOUNDARY + '--')
    L.append('')
    content_type = 'multipart/form-data; boundary=%s' % BOUNDARY
    body = CRLF.join(L)

    header = 'Content-Type:%s' % content_type
    length = 'Content-Length:%s' % len(body+content_type)

    headstr = CRLF.join([header,length, '',''])

    return content_type, headstr+body

# form_data = [('gShopID','489'),("addItems", r"f'D:\case3guomei.xml'"), ('validateString', '92c99a2a36f47c6aa2f0019caa0591d2')] 
# form_data_re = encode_multipart_formdata(form_data) 
# print form_data_re 
