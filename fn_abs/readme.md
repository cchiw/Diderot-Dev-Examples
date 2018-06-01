## A8. Math functions: Abs()
The absolute function can be used on fields
```
#version 2.0
field#2(1)[] A  (x) = x*2;
field#2(1)[] F = abs(A);
field#1(1)[] G = ∇F;
```
The derivative is derived as the following
```
output real out = |x*2|/(x*2);
```
### Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “abs”: field#k(d)[]  → field#k(d)[]
* [Examples:](https://github.com/cchiw/Diderot-Dev-Examples/tree/master/fn_abs) 


