# Field Selection
* Branch: Diderot Dev:https://github.com/cchiw/Diderot-Dev
* Functionality: Field assignment based on integer selector 
* Syntax: “swap()”
    - fty = field#k(d)[α]
    - int × fty × fty → fty
    - int × fty × fty× .... → fty
    - int × fty × fty × fty × fty × fty × fty → fty
    - Selection-id The first argument is an integer that serves to select a field. i.e. id=1 chooses the first field argument 
    - Field Arguments The function accepts 2-6 field arguments. anch
* Text: none
* Issues: Selection id is clamped when outside range (i.e. id=-6 → id=1) instead of throwing an error 
* Examples: 
    - Global Initialization . shaded v.r. program (dvr)  : X1
    - Set selection id in updated method  : X2