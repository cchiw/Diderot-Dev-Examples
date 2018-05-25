rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec base_sss.diderot
./base_sss
unu save -f nrrd -e ascii -i out.nrrd | less