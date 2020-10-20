
import os,logging
from utils.commandline import CMDBuilder as cmd
from pathlib import Path

logging.basicConfig(level = logging.INFO,format = '%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

class Node:
    def __init__(self):
        self.name = None
        self.path = None
        self.parent = None
        self.childrens = []

class ProjClass:
    def __init__(self):
        self.root = Node()

    def insert(self,pnode, node):
        pnode.childrens.append(node)

@cmd.cmdbuild('PFParser')
class ProjClassParser:
    def __init__(self):
        self.result = {}

    @cmd.Args('rootdir', help='root directory')
    @cmd.Args('-e','--exts',nargs='+',default=['h'], help='the extends names for project file')
    @cmd.Args('-o', '--ofile', help='result file output',default='result.org')
    def parse(self, rootdir, exts, ofile):
        logger.info("args %s, %s, %s" % (rootdir,exts,ofile))
        files = self._list_files(rootdir, exts)
        for f in files:
            logger.info('parse %s' % f)
            self._do_parse(f)
            break

    def _do_parse(self,f):
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
                l = l.replace(' ', '').replace('{','')
                r = l.split(':')
                if(len(r)==2):
                    classname = r[0]
                    baseclasses = r[1].split(',')
                    logger.debug("class name: %s,base class %s" % (classname,','.join(baseclasses)))
                    if classname in self.result:
                        self.result[classname].extend(baseclasses)
                    else:
                        self.result[classname] = baseclasses
                elif(len(r)==1):
                    classname = r[0]
                    if classname not in self.result:
                        self.result[classname]=[]
                else:
                    logger.error("parse error %s" % l)
        print(self.result)
        return self.result

    def _normalizational(self):
        for clsname, parents in self.result.items():
            result = []
            result.append(clsname)
            for parent in parents:
                result.append(parent)
                result.extend(_extra_parents(parent, self.result))
                pass

    def _normalization_parents(self):
        for clsname, parents in self.result.items():
            for i, parent in enumerate(parents):
                if parent in self.result:
                    if self.result[parent]:
                        print(clsname,parent)
                        self.result[clsname].insert(i,self.result[parent])
                        self.result[clsname][i].insert(0, parent)
                        self.result[clsname].remove(parent)
                        #del(self.result[parent])
                print(self.result)

    def _reduce_branches(self):
        for cls in self.result.values():
            if cls in self.result:
                del(self.result[cls])
        return self.result

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
    @cmd.Args('-e','--exts',nargs='+',default=['h'], help='the extends names for project file')
    def list(self, rootdir,exts):
        #import pdb;pdb.set_trace()
        fs =self._list_files(rootdir,exts)
        for f in fs:
            print(f)
if __name__ == "__main__":
    cmd.run()
