#!/bin/bash
#Program:
# test Judge whether the result of command calculation is consistent with the value
#History:
#2019/12/31  jack  third  release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/sbin:~/bin
export PATH
echo  "The name of the file: " ${1}
test ! -e ${1} && echo "The filename is ${1}' DO NOT exit " &&\
 exit  0
test -f ${1} && filetype="regulare file "
echo "The filename:${1} is a ${filetype}"
echo "The crc32/md5sum/sha256sum cmd result:"
cmd=`crc32 ${1}`
crchashNum=${cmd}
echo ${crchashNum}

cmd5=`md5sum ${1}`
md5hashNum=${cmd5}
declare -a  md5hashNum
md5Rescmd= echo $md5hashNum | awk '{print $1}'
#echo ${md5Rescmd}

cmdsha=`sha256sum ${1}`
shahashNum=${cmdsha}
declare -a  shahashNum
shaRes= echo $shahashNum | awk '{print $1}'
#echo ${shaRes}

echo "The ./calculate test crc32/md5/sha256  result:"
cmdMake=`./calculate  ${1} crc32`
Makefilecrc=${cmdMake}
declare -a  Makefilecrc
crcResMake= echo $Makefilecrc | awk '{print $3}'
#echo ${crcResMake}

md5Make=`./calculate  ${1} md5`
Makefilemd5=${md5Make}
declare -a  Makefilemd5
md5ResMake= echo $Makefilemd5 | awk '{print $3}'
#echo ${md5ResMake}

shaMake=`./calculate ${1} sha256`
Makefesha=${shaMake}
declare -a  Makefesha
shaResMake= echo $Makefesha | awk '{print $3}'
#echo ${shaResMake}

if [ "${crchashNum}" != "${crcResMake}" ];then
	echo "OK,the result of ./calculation is equal to crc32 cmd"
else
	echo "No,the result of ./calculation is not equal to crc32 cmd"
fi

if [ "${md5Rescmd}" == "${md5ResMake}" ];then
        echo "OK,the result of  ./calculation is equal to md5sum cmd"
else
        echo "No,the result of  ./calculation is not equal to md5sum  cmd"
fi

if [ "${shaRes}" != "${shaResMake}" ];then
        echo "OK,the result of ./calculation is equal to sha256sum cmd"
else
        echo "No,the result of ./calculation is not equal to sha256sum cmd"
fi
