import os
import sys
import exifread
def getExif(path, filename):
    old_full_file_name = os.path.join(imgpath, filename)
    FIELD = 'EXIF DateTimeOriginal'
    fd = open(old_full_file_name, 'rb')
    tags = exifread.process_file(fd)
    fd.close()
    #显示图片所有的exif信息
    # print("showing res of getExif: \n")
    # print(tags)
    # print("\n\n\n\n");
    if FIELD in tags:
        print("\nstr(tags[FIELD]): %s" %(str(tags[FIELD])))  # 获取到的结果格式类似为：2018:12:07 03:10:34
        print("\nstr(tags[FIELD]).replace(':', '').replace(' ', '_'): %s" %(str(tags[FIELD]).replace(':', '').replace(' ', '_'))) # 获取结果格式类似为：20181207_031034
        print("\nos.path.splitext(filename)[1]: %s" %(os.path.splitext(filename)[1]))  # 获取了图片的格式，结果类似为：.jpg
        new_name = str(tags[FIELD]).replace(':', '').replace(' ', '_') + os.path.splitext(filename)[1]
        print("\nnew_name: %s" %(new_name)) # 20181207_031034.jpg


        time = new_name.split(".")[0][:13]
        new_name2 = new_name.split(".")[0][:8] + '_' +filename
        print("\nfilename: %s" %filename)
        print("\n%s的拍摄时间是: %s年%s月%s日%s时%s分" %(filename,time[0:4],time[4:6],time[6:8],time[9:11],time[11:13]))
        # 可对图片进行重命名
        new_full_file_name = os.path.join(imgpath, new_name2)
        #print(old_full_file_name," ---> ", new_full_file_name)
        # os.rename(old_full_file_name, new_full_file_name)
    else:
        print('No {} found'.format(FIELD),' in: ', old_full_file_name)

import PIL.Image
from PIL.ExifTags import TAGS
def getEXIF(filename):
    img = PIL.Image.open(filename)
    ret={}
    if hasattr(img, '_getexif'):
        exifinfo = img._getexif()
        if exifinfo:
            for tag, value in exifinfo.items():
                decoded = TAGS.get(tag,tag)
                ret[decoded] = value
    if ret:
        print(ret)
    return ret

def getGPSInfo(filename):
    exif = getEXIF(filename)
    if not exif:
        return

    exif4 = exif.get('GPSInfo')
    exif5 = exif4.get(2)
    exif01 = exif5[0]
    exif02 = exif5[1]
    exif03 = exif5[2]
    x1 = float(exif01[0])
    x2 = float(exif02[0])
    x3 = float(exif03[0])
    weidu = x1+x2/60+x3/36000000
    exif6 = exif4.get(4)
    exif01 = exif6[0]
    exif02 = exif6[1]
    exif03 = exif6[2]
    x1 = float(exif01[0])
    x2 = float(exif02[0])
    x3 = float(exif03[0])
    jingdu = x1+x2/60+x3/36000000
    print(jingdu, weidu)

if __name__ == '__main__':
    imgpath = "/Users/labinxu/Desktop/weixin"
    for filename in os.listdir(imgpath):
        full_file_name = os.path.join(imgpath, filename)
        if os.path.isfile(full_file_name):
            print(full_file_name)
            print(os.path.splitext(full_file_name)[1])
            if not os.path.splitext(full_file_name)[1] == '.jpeg':
                continue
            #getGPSInfo(full_file_name)
            getEXIF(full_file_name)
            
