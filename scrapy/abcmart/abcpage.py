from core import login
import logging

logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)
class AbcMartPage(login.Login):
    """
    docstring
    """
    def __init__(self):
        super().__init__()
        
    def login(self, loginpage, playdata=None):
        resp = self.postSoup(loginpage, data=playdata)
        successfulTag = resp.find('a',attrs={'class':'mypage-logout'})
        status = True if successfulTag else False
        if not status:
            logger.error('Login Failed')
            with open('./loginerror.html','w',encoding='utf-8') as f:
                f.write(resp.text)
        else:
            print('login successful'+ successfulTag.text)
        return status, resp


