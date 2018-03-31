/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec mip_max.diderot
./mip_max -imgResU 200 -imgResV 200  -rayStep 0.01
unu quantize -i out.nrrd -b 8 -o s_14D.png
open s_14D.png