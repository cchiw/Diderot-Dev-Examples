# Math functions: Function composition
## Overview
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: "compose"  and "◦"
- field#k(d1)[α]× field#k(d0)[d1] → field#k(d1)[α]
* Text: EIN IR design, rewriting rules, and resolved bugs listed in Doc
## In Action
Given two fields
```
field#k(d1)[α]F0;
field#k(d0)[d1]F1;
```
A user might want to use the result of one field to probe the other, also known as field composition
```
tennsor[α] t = F0(F1(x));
```
The problem with ^ is that the result is a tensor (and no longer differentiable). Instead, added a field composition operator that can be applied to differentiable fields. 
```
field#k(d0)[α]G = F0 ∘ F1;
```
There is a type restriction on this type of operation:
field#k(d1)[α]× field#k(d0)[d1] → field#k(d1)[α]
>The second argument is a vector field, whose length is the dimension of the first argument. 

The function name  "compose" can also be used
```
field#k(d0)[α]G = compose(F0,F1);
```
The field arguments can be created as the result of another operation.
```
field#k(d0)[α]G = compose(F0, A∙B);
```
> **Note:** The result of (A∙B) must still fit the type requirements mentioned earlier

The user might want to chain multiple composition operators: 
```
field#k(d0)[α]G = F0 ∘ F1∘ F2;
```
> **Note:** The new field variable F2 will have to meet the same type  requirements mentioned earlier


## Directory Organization
* Examples
- Chaining composition  : X2
- Test programs that created bugs (now solved)  : B*.diderot
- Unicode syntax  : X1/observ.diderot and X2/t.diderot

