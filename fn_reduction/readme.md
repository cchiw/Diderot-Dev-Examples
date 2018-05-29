
## Math functions: Reduction

Probe an input-variable field at a sequence of positions then appy a reducation operator over the result.

### In Action 

The following code defines an variable input field and a sequence of positions
``
    field#3(1)[] F (r) = r*8;
    strand sample (int R) {
        real[5] X= {3,7,R,2,1};
        ...
    }
``
The following short-hand function probes the field at a sequence of positions then applies a reduction over the result.
``
    output tensor[] out= SUM(F, X);
``

The computation does the following:

      out = F(X<sub>0</sub>)+ X<sub>1</sub>)++ X<sub>2</sub>)..
      out = F(3)+ F(7)+F(R)+...
      out = 3*8+ 7*8+  R*8+...

Other reducation operators include getting the maximum and mininum.

``
    output tensor[] out= MAX(F, X)
    output tensor[] out= MIN(F, X);
``

### Implementation Details 
- EIN Reduction operation wrapped inside probe terms and expanded in high-to mid
- High to mid creates variable binding in reduction operation and sequence EIN expression
- Easy translation from mid-to-low 

### Overview 
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: SUM(), MAX(), MIN()
    - SUM : field#k(d)[] × tensor[d]{n} →  real
    - MAX : field#k(d)[] × tensor[d]{n} →  real
    - Min : field#k(d)[] × tensor[d]{n} →  real

## Directory Organization
* sequence of reals : X1
* sequence of vectors : X2
* Summation over a vector fields : X3

