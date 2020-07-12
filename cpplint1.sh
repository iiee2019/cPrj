#!/bin/bash
#Program:
# use cpplit to check file1,file2
#History:
#2020/02/20  jack  first  release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/sbin:~/bin
export PATH
cpplint_path=/usr/local/lib/python2.7/dist-packages/cpplint.py
config='--filter=-whitespace,-readability,-legal'
parm=${1}
index=0

if [ $parm == "*" ]
then
   `sudo python $cpplint_path  $config ls -f`
else
  `sudo python $cpplint_path  $config $*`
fi

for file in `find $src_path -maxdepth 1 -type f | grep -E "\.h$|\.cc$|\.cu$|\.cpp$"`
do
    echo file=$file
    echo -e "\033[36m ===> [FILE] \033[0m \033[47;31m $file \033[0m"
    check_files[$index]=$file
    index=$(($index+1))
    `sudo python $cpplint_path  $config ls -f`
done
