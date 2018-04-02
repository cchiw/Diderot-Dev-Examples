# Math functions: Function concatenation
## In Action
Given two fields
```
field#k(d)[i] A;  field#k(d)[i] B;
```
A user might want to put two fields together to create a new field
```
field#k(d)[2,i] M = concat(A,B)
```
> **Note:** The two fields have the same type
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: "concat"
- field#k(d)[α] × field#k(d)[α] → field#k(d)[2,α]
* Text: Mentioned in dissertation-FW. Details provided in Doc
* Future work Use syntax “[”,“]”

## Directory Organization
* Examples
- Test programs that created bugs (now solved)  : B*.diderot
