/Users/chariseechiw/diderot/chiw17/bin/diderotc --exec mip_max.diderot
./mip_max -imgResU 200 -imgResV 200  -rayStep 0.01
unu quantize -i out.nrrd -b 8 -o k_18.png
open k_*.png