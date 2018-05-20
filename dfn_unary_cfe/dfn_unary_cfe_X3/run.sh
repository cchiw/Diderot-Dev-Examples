rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec dfn_unary_cfe_X3.diderot
./dfn_unary_cfe_X3
sh assess.sh
rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec sphere.diderot
./sphere
unu save -f nrrd -e ascii -i out.nrrd | less