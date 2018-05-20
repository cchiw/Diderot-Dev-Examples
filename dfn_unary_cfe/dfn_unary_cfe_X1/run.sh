rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec dfn_unary_cfe_X1.diderot
./dfn_unary_cfe_X1
unu save -f nrrd -e ascii -i out.nrrd | less