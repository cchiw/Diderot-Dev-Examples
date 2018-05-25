rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec clip.diderot
./clip
unu save -f nrrd -e ascii -i out.nrrd | less
sh assess.sh
