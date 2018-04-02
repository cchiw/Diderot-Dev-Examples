rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec m3.diderot
./m3
unu save -f nrrd -e ascii -i out.nrrd | less