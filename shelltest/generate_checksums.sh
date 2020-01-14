#!/bin/bash

PIDARRAY=()
for file in sorted.txt stdout.txt
do
   md5sum $file &
   PIDARRAY+=("$!")
done
wait ${PIDARRAY[@]}
