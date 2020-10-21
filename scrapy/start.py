from abcmart import abcmart
import sys
from core import cmdline

if __name__=='__main__':
    site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
    ret , _= site.login('flowinair@gmail.com','wukong110')
    if not ret:
        print("exit")
        sys.exit(1)
    site.addcart('6025230001012')
    #site.submitOrder()
