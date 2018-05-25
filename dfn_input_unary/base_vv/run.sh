rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec base_vv.diderot
./base_vv
unu save -f nrrd -e ascii -i out.nrrd | less
sh assess.sh