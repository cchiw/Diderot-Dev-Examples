rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec dfn_cfe_X3.diderot
./dfn_cfe_X3
unu save -f nrrd -e ascii -i out.nrrd | less