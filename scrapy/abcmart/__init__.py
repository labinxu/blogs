# def jwkj_get_filePath_fileName_fileExt(filename):
#     (filepath,tempfilename) = os.path.split(filename)
#     (shotname,extension) = os.path.splitext(tempfilename);
#     return filepath,shotname,extension
import sys
sys.path.append('..')
from abcmart import abcmart
def GetSite():
    return abcmart.AbcMart('abcmart','www.abc-mart.net')