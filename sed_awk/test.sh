#!/bin/bash

#result=`ifconfig | grep -E "^eth0.*" | grep -E -o "([0-9A-F]{2}:){5}[0-9A-F]{2}" | sed 's/://g'`
result=`ls`
echo $result
