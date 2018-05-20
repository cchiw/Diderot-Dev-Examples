rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec dfn_unary_cfe_X12.diderot
./dfn_unary_cfe_X12
unu save -f nrrd -e ascii -i out.nrrd | less