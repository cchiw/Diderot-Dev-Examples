rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec enr.diderot
./enr
unu save -f nrrd -e ascii -i out.nrrd | less