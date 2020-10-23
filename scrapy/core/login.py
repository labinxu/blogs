#!/bin/env python
from . import page
from bs4 import BeautifulSoup
#pip install fake-useragent
from . import logmanager
logger = logmanager.LogManager().getLogger()

class Login(page.Page):
    def __init__(self, securetype='http', port='80', domain=''):
        super().__init__()
        self.username = ''
        self.password = ''
        self.csrftoken = ''
        self.server = ''
        self.securetype = securetype
        self.port = port

    def set_port(self, port):
        assert(port)
        self.port = port

    def set_secure(self,insecure=True):
        if insecure:
            self.securetype = 'http'
        else:
            self.securetype = 'https'

    def make_url(self, server, page):
        url = '{ttype}://{server}:{port}/{page}'.format(ttype=self.securetype, server=server, port=self.port, page=page)
        logger.debug(url)
        return url

    def login(self, loginpage, data=None,**kwagrs):
        #resp = self.postSoup(loginpage, data=data)
        self.post(loginpage,data=data,**kwagrs)
        resp = self.get(loginpage,**kwagrs)
        return BeautifulSoup(resp.text.encode('utf-8'), 'html.parser')