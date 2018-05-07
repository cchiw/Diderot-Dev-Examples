rm rgb.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec lic.diderot
./lic
unu project -i rgb.nrrd -a 1 -m mean |  unu quantize -b 8 -min 0 -max 1 -o lic_ctmr-c4hexic.png