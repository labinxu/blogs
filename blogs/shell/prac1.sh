#!/bin/dash

#1.1 参数
#prac1.sh arg1 args2
# 参数的个数
numberofargmuments(){
    echo "The number of args: " "$#"
    #>> 2
    # $0 当前执行脚本的相对路径
    echo "shell script path:" $0
    #$1 $2 分别代表第一 第二个参数
    # 获取当前脚本的路径1
    currentdir=$(cd $(dirname $0)|pwd)
    echo "current dir is(cd dirname pwd)": "$currentdir"
    # 说明 $(dirname $0) 获取当前脚本的目录的相对路径,cd 进去 执行pwd获得全路径
    # 获取当前脚本的路径2
    currentdir=$(dirname $(readlink -f $0))
    echo "current dir is(dirname readlink -f)": "$currentdir"
}
# uncomment
# numberofargmuments $*
#1.2
#参数的处理 1
# $* 除$0以外的所有参数, 是一个完整的字符串

# $@ 除$0以外的所有参数, 是一个数组
# 两者区别可以用下面的代码看出来
##./prac1.sh arg1 arg2
arguments_deal1(){
    echo print '$*'
    for arg in "$*";do
        echo "$arg"
    done
    # arg1 arg2 输出为一行
    echo print '$@'
    for arg in "$@";do
        echo "$arg"
    done
    # 输出为2行
    # arg1
    # arg2
}
# uncomment it
#arguments_deal1 $@
#arguments_deal1  $*

#1.3 参数处理2
argment_deal2(){
    # ./prac1.sh -m option or ./prac1.sh option -m
    # 如何取出option
    #可以先判断$1 or $2 然后再取出option
    if [ "$1" = "-m" ];then
        echo '$0' is -m and value is: $2
    fi
    #or
    if [ "$2" = "-m" ];then
        echo '$2' is -m and value is: $1
    fi
}

# uncommtents
# argment_deal2 $@

# 参数处理3 shift 会将参数往左移动一位，也就相当于删除第一个参数
# eg:./prac1.sh -f v1 v2 v3  or ./prac1.sh v1 v2 v3 -f
arguments_deal3(){
    values=""
    while [ -n "$1" ];do
        if [ "$1" = "-f" ];then
            shift 
            continue
        else
            values="$values $1"
        fi
        shift
    done

    echo argments values:"$values"
}
#arguments_deal3 $@


manipulatestring(){
    var="/user/home/user1"
    echo ${var#*home/} # 去掉*home/ 留下 user1

    # split 字符串
    echo ========split string==========
    vars=$(echo $var | tr '/' ' ')
    for v in ${vars};do
        echo $v
    done

    # 计算个数
    echo ========count==========
    count=0
    vars=$(echo $var | tr '/' ' ')
    for v in ${vars};do
        #count=$count+1 # count=0+1+1+1
        #计算需要用expr 命令
        count=`expr $count + 1`
    done
    echo count=$count

    #字符串拼接
    joinedstr=""
    for v in ${vars};do
        #if [ $joinedstr = "" ];then #error [: =: unexpected operator
        if [ "$joinedstr" = "" ]; then

            joinedstr=$v
        else
            joinedstr="$joinedstr#$v"
        fi
    done
    echo joinedstr=$joinedstr
}
#manipulatestring
folder(){
    files=$(ls | sed "s:^:`pwd`/: ")
    #files=`ls -A /home/xulai/wks/report/*`
    for file in $files;do echo $file
    done
}
folder
# https://www.cnblogs.com/Malphite/p/7742406.html
# https://www.cnblogs.com/zwgblog/p/6031256.html
# https://www.cnblogs.com/xuxm2007/p/7554543.html
# https://www.cnblogs.com/wangtao1993/p/6136894.html
