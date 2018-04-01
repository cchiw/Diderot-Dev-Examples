# Math functions: Clerp and Clamp
## Overview

* Branch:  [Vis15](http://smlnj-gforge.cs.uchicago.edu/scm/viewvc.php/branches/vis15/?root=diderot) & [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “clerp()” New Clerp function 
- tensor[i] × tensor[i] × real → tensor[i]
- tensor[i] × tensor[i] × real × real × real → tensor[i]
* Syntax: “clamp()” Clamp function can be applied to general tensors
- tty = tensor[α]
- tty × tty × tty → tty
## In Action
It is typical for a  user to use clamp and lerp sequentially and on scalars
```
vec2 a; vec2 b; real t;
real xx = clamp(a[0], b[0], lerp(a[0], b[0], t));
real yy = clamp(a[1], b[1], lerp(a[1], b[1], t));
vec2 out = [xx,yy];
```
We addressed this issued in two ways. The first was to allow non-scalar arguments to math functions clamp() and lerp()
```
vec2 out = clamp (a, b, lerp(a, b, t))
```
The second was to create the new clerp() function 
```
vec2 out = clerp (a,b,t)
```
which will apply clamp and lerp as expected.
## Directory Organization
* new function clerp()  : clerp3.diderot 
* clamp() applied to matrices  : clamp.diderot
*  lerp()  : lerp3.diderot, lerp5.diderot
