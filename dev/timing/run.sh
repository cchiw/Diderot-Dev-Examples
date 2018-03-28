echo "chiw17 mode-high"
/Users/chariseechiw/diderot/chiw17/bin/diderotc --exec  Vmode-High.diderot
./Vmode-High --timing
cp Vmode-High.cxx chiw17.cxx
echo "ein16 mode-high"
/Users/chariseechiw/diderot/ein16/bin/diderotc Vmode-High.diderot
./Vmode-High -timing
cp Vmode-High.c ein16.c
echo "vis15 mode-high"
/Users/chariseechiw/diderot/vis15/bin/diderotc --exec  Vmode-High.diderot
./Vmode-High --timing
cp Vmode-High.cxx vis15.cxx
echo "chiw17 mode-high-- --scaFlag "
/Users/chariseechiw/diderot/chiw17/bin/diderotc --exec   --scaFlag  Vmode-High.diderot
./Vmode-High --timing
echo "ein16 mode-high-no slice"
/Users/chariseechiw/diderot/ein16/bin/diderotc --disable-sliceFlag Vmode-High.diderot
./Vmode-High -timing
echo "ein16 mode-high-only scalars"
/Users/chariseechiw/diderot/ein16/bin/diderotc  --enable-scaFlag Vmode-High.diderot
./Vmode-High -timing
echo "chiw17 mode-high--disable-sliceFlag "
/Users/chariseechiw/diderot/chiw17/bin/diderotc --exec    --scaFlag --disable-sliceFlag Vmode-High.diderot
./Vmode-High --timing
echo "chiw17 mode-high--disable-sliceFlag "
/Users/chariseechiw/diderot/chiw17/bin/diderotc --exec    --scaFlag --replaceFlag --disable-sliceFlag Vmode-High.diderot
./Vmode-High --timing
echo "chiw17 mode-high-- --disable-fullSplitFlag "
/Users/chariseechiw/diderot/chiw17/bin/diderotc --exec   --scaFlag  --disable-fullSplitFlag  Vmode-High.diderot
./Vmode-High --timing
echo "chiw17 mode-high-- --replaceFlag "
/Users/chariseechiw/diderot/chiw17/bin/diderotc --exec     --scaFlag --replaceFlag  Vmode-High.diderot
./Vmode-High --timing
