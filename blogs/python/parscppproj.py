import os,logging
from utils.commandline import CMDBuilder as cmd
from pathlib import Path

logging.basicConfig(level = logging.INFO,format = '%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

class ProjClass:
    def __init__(self):
        self.childrens = []
        self.name = None
        self.path = None

@cmd.cmdbuild('PFParser')
class ProjClassParser:
    def __init__(self):
        self.results = {}

    @cmd.Args('rootdir', help='root directory')
    @cmd.Args('-e','--exts',nargs='+',default=['cc','cpp','h'], help='the extends names for project file')
    @cmd.Args('-o', '--ofile', help='result file output',default='result.org')
    def parse(self, rootdir, exts, ofile):
        logger.info("args %s, %s, %s" % (rootdir,exts,ofile))
        files = self._list_files(rootdir, exts)
        for f in files:
            logger.info('parse %s' % f)
            self._do_parse(f)
            break

    def _do_parse(self,f):
        result = {}
        with open(f) as data:
            for l in data.readlines():
                l = l.strip()
                # skip predefined comments
                if not l or l[-1] == ';' or l[0:2] == "//":
                    continue
                # class D : public b
                # class a : public c, public b
                # skip not define
                if not l[0:len('class')] == 'class':
                    continue
                l = l.replace('class', '').replace('public', '').replace('protected', '').replace('private', '')
                l = l.replace(' ', '')
                r = l.split(':')
                if(len(r)==2):
                    classname = r[0]
                    baseclasses = r[1].split(',')
                    logger.debug("class name: %s,base class %s" % (classname,','.join(baseclasses)))
                    for c in baseclasses:
                        if c in result:
                            result[c].append(classname)
                        else:
                            result[c] = [classname]
                elif(len(r)==1):
                    classname = r[0]
                    if classname not in result:
                        result[classname]=[]
                else:
                    logger.error("parse error %s" % l)
        print(result)

    def _output(self, data, ofile):
        with open(ofile) as f:
            for key,value in data.items():
                level = 0

    def _getlevel(self,classname, data):
        level = 1;
        if classname in data:
            for vs in data[classname].values():
                pass

    def _list_files(self, root, exts):
        #files = []
        # for dirpath, dirnames, filenames in os.walk(root):
        #     for filepath in filenames:
        #         print("filepath",dirnames)
        #         extname = os.path.splitext(filepath)[1]
        #         if extname in exts:
        #             files.append(os.path.join(dirpath,filepath))
        # return files
        p = Path(root)
        if len(exts)>1:
            pattern ='*.[%s]'%'|'.join(exts)
        else:
            pattern = '*.%s'%exts[0]

        logger.info('wildcard: %s/%s' % (root,pattern))
        return p.rglob(pattern)

    @cmd.Args('rootdir', help='root directory')
    @cmd.Args('-e','--exts',nargs='+',default=['cc','cpp','h'], help='the extends names for project file')
    def list(self, rootdir,exts):
        #import pdb;pdb.set_trace()
        fs =self._list_files(rootdir,exts)
        for f in fs:
            print(f)
if __name__ == "__main__":
    cmd.run()
