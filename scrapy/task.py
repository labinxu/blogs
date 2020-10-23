import importlib
class Task():
    def __init__(self,name,**kwargs):
        '''
        **kwargs:sitename 
        account
        proxies

        taskdata 
        '''
        self.taskname = name
        module = importlib.import_module(name)
        site = module.GetSite()
        site.login('flow@gmail.com','juyoujin110')

Task("abcmart")