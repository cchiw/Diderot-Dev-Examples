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
> **Note:** 
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: "if else"  
    -  field#k(d)[α]× boolean×field#k(d)[α] → field#k(d)[α]
* Notes :
    - Still under development
    - Created new *simple* expressions in the compiler
    - boolean is constant variable
* Issues for compiler :
    - Fields can't be defined inside update? Swap operator is better

## Directory Organization
* Examples
    - Basic Example  : X1
    - Gradient of If Statement : X2

