rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec dfn_cfe_X6.diderot
./dfn_cfe_X6
unu save -f nrrd -e ascii -i out.nrrd | less