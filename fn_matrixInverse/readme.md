# Math functions: Matrix Inverse
## In Action
Given matrix M and a second order tensor field F
```
tensor[d,d] M;  
field#k(d)[d,d] F;
```
A user can take the matrix inverse 
```
tensor[d,d] MI = inv(M);  
field#k(d)[d,d] FI = inv(F)
```
> **Note:** The two fields have the same type
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “inv()”
- field#k(d)[d,d] → field#k(d)[d,d]
- tensor[n,n] → tensor[n,n]
* Text: Mentioned in dissertation-Design

## Directory Organization
* Examples
- Inverse of Negation  : X1
- Hessian of Inverse  : X2
- Inverse of Hessian Times another field  : X3

