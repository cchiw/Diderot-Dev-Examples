rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec X3.diderot
./X3
unu save -f nrrd -e ascii -i out.nrrd | less
sh assess.sh
