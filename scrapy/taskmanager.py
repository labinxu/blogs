from abcmart import abcmart
import sys,json
from core.cmdline import CMDBuilder
from abcmart import abcmart

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
        pass
    # @CMDBuilder.Args('-s','--sitename', help='sitename')
    # @CMDBuilder.Args('-g', '--gcode',   help='gcode')
    def run(self):
        #print(self.configure[sitename])
        task = Task()

if __name__ == "__main__":
    CMDBuilder.run()