rm tmp*.png
/Users/chariseechiw/diderot/Diderot-Dev/bin/diderotc --exec dvr.diderot
PARAMS="-camEye 10 20 5 -camAt 0 0 0 -camUp 0 0 1 -camNear -2 -camFar 2 -camFOV 8 -iresU 400 -iresV 400 -thick 0.1 -refStep 0.1 -rayStep 0.01 -isoval 0.0 -cmin -1 -cmax 1 -vol1 "../../data/parab3s.nrrd" -vol2 "../../data/vol_gquartic.nrrd""



./dvr $PARAMS -selection 1
overrgb -i rgba.nrrd -b 1 1 1 -g 1.2 -o Ctmp_shape_1.png
./dvr $PARAMS -selection 2
overrgb -i rgba.nrrd -b 1 1 1 -g 1.2 -o Ctmp_shape_2.png
./dvr $PARAMS -selection 3
overrgb -i rgba.nrrd -b 1 1 1 -g 1.2 -o Ctmp_max.png
./dvr $PARAMS -selection 4
overrgb -i rgba.nrrd -b 1 1 1 -g 1.2 -o Ctmp_min.png

open *.png