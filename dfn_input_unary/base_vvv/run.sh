rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec base_vvv.diderot
./base_vvv
unu save -f nrrd -e ascii -i out.nrrd | less