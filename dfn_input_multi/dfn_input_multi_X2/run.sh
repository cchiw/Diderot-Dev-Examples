rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec dfn_input_multi_X2.diderot
./dfn_input_multi_X2
unu save -f nrrd -e ascii -i out.nrrd | less