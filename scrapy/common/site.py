import logging
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

class Site():
    def __init__(self,name,url):
        self.name = name
        self.url=url
        self.page=None