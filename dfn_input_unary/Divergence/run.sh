rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec Divergence.diderot
./Divergence
unu save -f nrrd -e ascii -i out.nrrd | less