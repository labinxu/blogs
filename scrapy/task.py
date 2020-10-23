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
        sitename = kwargs.pop('sitename',None)
        site = None
        if not sitename:
            if sitename=='abcmart':
                import abcmart as module
                site = module.GetSite()
        else:
            import abcmart as module
            site = module.GetSite()
        #module = importlib.import_module(name)
        
        #user = kwargs.pop("user", None)
    
        site.login('flow@gmail.com','juyoujin110')

Task("abcmart",sitename='abcmart')