rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec base_v.diderot
./base_v
unu save -f nrrd -e ascii -i out.nrrd | less
sh assess.sh