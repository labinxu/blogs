

class Site():
    def __init__(self,name,url):
        self.name = name
        self.url=url
        self.page=None
        self.proxies = {}