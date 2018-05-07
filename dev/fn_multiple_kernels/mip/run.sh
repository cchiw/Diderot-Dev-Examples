rm out.nrrd
rm rgb.nrrd
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec mip.diderot
./mip -vol parab0.nrrd -out0 0 -camFOV 20 -rayStep 0.03 -iresU 300 -iresV 300
unu quantize -b 8 -min 0 -max 1 -i out.nrrd -o p0-bspln3-ctmr,ctmr.png
