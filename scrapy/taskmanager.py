from abcmart import abcmart
import sys,json
from core.cmdline import CMDBuilder
from abcmart import abcmart
import logging
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

class Task():
    def __init__(self):
        site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
        ret , _= site.login('flow@gmail.com','juyoujin110')
        if not ret:
            print("exit")
            sys.exit(1)
        site.addcart('6025230001012')

@CMDBuilder.cmdbuild('Task')
class TaskManger():
    def __init__(self):
        #init the site configure fil
        pass

    @CMDBuilder.Args('-u', '--user',   help='user')
    @CMDBuilder.Args('-p', '--passwd',   help='password')
    @CMDBuilder.Args('-g', '--gcode',   help='gcode')
    def run(self, user,passwd, gcode):
        site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
        ret , _= site.login(user,passwd)
        if not ret:
            logger.error("===Login Failed")
            sys.exit(1)
        # get product list
        site.addCart(gcode)
        site.submitOrder()

    @CMDBuilder.Args('-g', '--gcode',   help='gcode')
    @CMDBuilder.Args('-t', '--token',   help='token')
    def get(self,gcode,token):
        site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
        # get product list
        pd = site.getProductData(gcode,token)
        for size,gcode in pd.items():
            print(size,gcode)
        #proxies = 137.220.240.253:42063:mulgmqzc:skmyqbml
    @CMDBuilder.Args('-u', '--user',   help='user')
    @CMDBuilder.Args('-p', '--passwd',   help='password')
    def order(self,user,passwd):
        site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
        site.login(user,passwd)
        site.submitOrder()


    @CMDBuilder.Args('-u', '--user',   help='user')
    @CMDBuilder.Args('-p', '--passwd',   help='password')
    def login(self,user,passwd):
        site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
        ret , _= site.login(user,passwd)
        if not ret:
            logger.error("==Login Failed")
            sys.exit(1)

    @CMDBuilder.Args('-u', '--user', help='user')
    @CMDBuilder.Args('-P', '--proxy', default='', help='proxies servers')
    def cart(self,user, proxy):
        site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
        site.cart(user)
        
        
    @CMDBuilder.Args('-u', '--user', help='user')
    @CMDBuilder.Args('-P', '--proxy', default='', help='proxies servers')
    def proxy(self,user,proxy):
        proxies = {
            'http': 'http://' + proxy,
	        'https': 'https://' + proxy}
        site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
        site.addProxy(user, proxies)
        site.activeProxy(user)

if __name__ == "__main__":
    CMDBuilder.run()