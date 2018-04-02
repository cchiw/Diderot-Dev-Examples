rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec v.diderot
./v
unu save -f nrrd -e ascii -i out.nrrd | less