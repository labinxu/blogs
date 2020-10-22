from abcmart import abcmart
import sys


if __name__=='__main__':
    taskdata={
        'gcode':'6025230001012',
        'number':'6'
    }
    site =abcmart.AbcMart("abcmart","https://gs.abc-mart.net")
    ret , _= site.login('flow@gmail.com','juyoujin110')
    if not ret:
        print("exit")
        sys.exit(1)
    site.addcart('6108450001043')
    #site.submitOrder()
