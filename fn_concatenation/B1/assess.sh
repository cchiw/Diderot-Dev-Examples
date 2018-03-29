#!/bin/sh

if [ ! -r out.nrrd ] ; then
  echo "fail"
  exit
fi


DOUBLE="--double"
if [ "$1" == "$DOUBLE" ]; then
unu 2op - out.nrrd correct_dbl.nrrd \
| unu reshape -s 1 64 \
| unu project -a 1 -m l1 \
| unu save -f text
else
unu 2op - out.nrrd correct_sng.nrrd \
| unu reshape -s 1 64 \
| unu project -a 1 -m l1 \
| unu save -f text
fi