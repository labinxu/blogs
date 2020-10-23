import logging
from . import singletontype

#logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')

class LogManager(metaclass=singletontype.SingletonType):
    def __init__(self):
        self.logger = logging.getLogger(__name__)
        logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        self.name = None

    def config(self,**kwargs):
        logging.basicConfig(**kwargs)
        return self

    def getLogger(self):
        return self.logger
    def setname(self,name):
        self.name=name
# l=LogManager().config(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s').getLogger()
# l.debug("aa")
# l.info("info")
# l.error('err')
# can not work below
# LogManager().config(level=logging.DEBUG)
# l=LogManager().getLogger()
# l.debug("aa")