#!/bin/sh

if [ ! -r out.nrrd ] ; then
  echo "fail"
  exit
fi

unu 2op - out.nrrd correct.nrrd \
| unu reshape -s 1 200 \
| unu project -a 1 -m l1 \
| unu save -f text
