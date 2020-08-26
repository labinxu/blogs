#!/bin/bash
print="False"
content=""
while read line;do
    data=`echo "$line" | awk -F' ' '{printf $3}'`
    if [ $data = "host" ];then
        if [ $print = "True" ];then
            echo $content
            print="False"
        fi
        # new host data 
        content=$line
    else
        if [ $data = "0" ]; then
            print="True"
            content+=$line
        fi
    fi

done<"./osd_tree.txt"

echo $content
