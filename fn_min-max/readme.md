# Math functions: Min and Max
## In Action
Given two scalar fields 
```
tensor[] M;  
field#k(d)[] A;
field#k(d)[] B;
```
A user can compare them by taking the maximum and minimum 
```
field#k(d)[] F = MaxF(A,B);  
field#k(d)[] G = MinF(A,B)
```
Then take the derivative 
```
field#k-1(d)[d] F = ∇ Max(A,B);  
```
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “MaxF” and "MinF"
    -  field#k(d)[] ×  field#k(d)[] →  field#k(d)[]
* Future work: change "MaxF()" to just "Max()”
## Directory Organization
* Examples:
    - Max()  : X1
    - Gradient of Max  : X2
    - Min()  : X3
    - Mip of Max  : X4
    - Shaded VR (Dvr)  : X5
    - Test programs that created bugs (now solved)  : B*.diderot

