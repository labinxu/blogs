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

    def login(self, loginpage, data=None,**kwagrs):
        resp=super().login(loginpage, data, **kwagrs)
        successfulTag = resp.find('a',attrs={'class':'mypage-logout'})
        print(self.session.cookies)
        status = True if successfulTag else False
        if not status:
            logger.error('Login Failed')
            with open('./loginerror.html','w',encoding='utf-8') as f:
                f.write(resp.text.encode('utf-8'))
        else:
            print('login successful'+ successfulTag.text)
        return status, resp

    def verifyCookie(self,loginpage,cn):
        if not self.activeCookie(cn):
            return False
        resp = self.getSoup(loginpage)
        successfulTag = resp.find('a',attrs={'class':'mypage-logout'})
        status = True if successfulTag else False
        if not status:
            logger.error('Login Failed')
        else:
            print('login successful'+ successfulTag.text)
        return status

