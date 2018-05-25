rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec circle.diderot
./circle
unu save -f nrrd -e ascii -i out.nrrd | less