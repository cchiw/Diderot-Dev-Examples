rm out.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec observ.diderot 
./observ
unu reshape -i out.nrrd -s 12 8  | unu save -f text -o "output.txt"