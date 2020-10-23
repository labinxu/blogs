import json
from core import singletontype

class AccountManger(metaclass=singletontype.SingletonType):
    def __init__(self):
        with open('../conf/accounts.conf') as f:
            self.accounts = json.loads(f.read())
    def get(self, uid):
        return self.accounts[uid]

    def getAccounts(self):
        return self.accounts

class SiteManager(metaclass=singletontype.SingletonType):
    def __init__(self):
        with open('../conf/sites.conf') as f:
            self.sites = json.loads(f.read())
    def get(self,sitename):
        return self.sites[sitename]
    def getSites(self):
        return self.sites