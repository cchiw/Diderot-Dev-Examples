# Math functions: Function concatenation
## In Action
Given two fields
```
field#k(d)[α] A;  field#k(d)[α] B; field#k(d)[α] C;
```
A user might want to put two fields together to create a new field
```
field#k(d)[3,α] M = [A,B,C]
```
> **Note:** The field arguments must have the same type
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: ``[``,``]``
    - field#k(d)[α] × field#k(d)[α]× ....field#k(d)[α] → field#k(d)[n,α] where n is the number of arguments
* Syntax:``concat``
    - field#k(d)[α] × field#k(d)[α] → field#k(d)[2,α]
* Text: `concat` Mentioned in dissertation-FW. 

## Directory Organization
* Use of bracket ``[]`` or ``concat``to create a field  : X1
* Test programs that created bugs (now solved)  : B*
