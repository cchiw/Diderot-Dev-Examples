rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec X1.diderot
./X1
unu save -f nrrd -e ascii -i out.nrrd | less