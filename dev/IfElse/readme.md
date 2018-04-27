# Math functions: If then Else
## In Action
Given two fields
```
field#k(d)[α]F0=..
field#k(d)[α]F1=..
```
Apply if then and else on fields
```
bool g =true;
field#k(d)[α] G = F0 if (g) else F1;
```
> **Note:** Still under development and has not be throughly tested
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: "if else"  
    -  field#k(d)[α] × boolean × field#k(d)[α] → field#k(d)[α]
* Issues :
    - Conditional expression can't be an input (yet)
    - Needs to be run with "--dev"
* Issues not isolated to this function :
    - Fields can't be defined inside update 
* Development:
    - Created new *simple* expressions in the compiler, perhaps not a long term solution
## Directory Organization
* Examples
    - Basic Example  : X1
    - Gradient of If Statement : X2

