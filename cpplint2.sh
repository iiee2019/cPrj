#!/bin/bash
#Program:
# use cpplit to check file1,file2
#History:
#2020/02/20  jack  first  release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/sbin:~/bin
export PATH
cpplint_path=/usr/local/lib/python2.7/dist-packages/cpplint.py
config='--filter=-whitespace,-readability,-legal'

index=0
src_path=`pwd`

#check_cmd="sudo python  $cpplint_path  $config ls -f"


for file in `find $src_path -maxdepth 1 -type f | grep -E "\.h$|\.c$|\.cu$|\.cpp$"`
do
    echo file=$file
   # echo -e "\033[36m ===> [FILE] \033[0m \033[47;31m $file \033[0m"
    check_files[$index]=$file
    index=$(($index+1))
   # "$check_cmd"$"check_files[index]"
done
  

check_cmd="sudo python  $cpplint_path  $config ls -f"
is_python2_exists=`ls "$cpplint_path" | grep -E '^python2$' | wc -l`
if [ $is_python2_exists -ge 1 ]
then
    # read cpplint.ini to decide which option to add
    for file in ${check_files[*]}
    do
       # check_cmd="python2 $cpplint_path --linelength=80"
       # check_cmd="sudo python  $cpplint_path  $config ls -f"
       # echo -e "\033[33m =========== check file $file =============\033[0m"
       check_file_cmd=`$check_cmd $file`
       eval $check_file_cmd
       # echo -e "\033[45m ==========================================\033[0m"
    done
fi

