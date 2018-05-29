rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec X2.diderot
./X2
unu save -f nrrd -e ascii -i out.nrrd | less
sh assess.sh
