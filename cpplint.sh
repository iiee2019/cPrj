#!/bin/bash
#Program:
# use cpplit to file1,file2
#History:
#2019/12/31  jack  first  release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/sbin:~/bin
export PATH
cpplint_path=/usr/local/lib/python2.7/dist-packages/cpplint.py
config='--filter=-whitespace,-readability,-legal'
parm=${1}

if [ $parm == "*" ]
then
   `sudo python $cpplint_path  $config ls -f`
else
  `sudo python $cpplint_path  $config $*`
fi

