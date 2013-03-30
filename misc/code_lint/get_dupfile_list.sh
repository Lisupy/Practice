#!/bin/sh
find . -name *.c > file_list
find . -name *.h >> file_list
find . -name *.cpp >> file_list
while read line; do
basename $line
done < file_list | sort | uniq -d > duplicate_list
while read line; do
echo "$line";
find . -name "$line" -exec ls -al {} \;
done < duplicate_list

