# Field Definition: Closed Form expression

Users can define closed form expressions. The expression can include tensor operators and variables.  Differentiation is applied by differentiating in respect to some variable(s).
	
## In Action
It is natural to define a function with an expression: F(x) = x²
In the surface language we added function cfexp() where the first argument exp is an expression and the second x is a variable.
 ``` 
tensor [] exp = x*x;  
field#k(1)[] F = cfexp(exp,x);//define F with variable x 
tensor[2] v = [3,7];  
tensor[] outF = inst(F,v);//evaluate F with argument v
 ```
 	> *Note* For this feature continuity k and dimension is unchecked and unuseful. New syntax being developed.
We commonly refer to the right-hand-side to variable F as a cfexp (closed-form expression). The cfe is created with variable x, but is actually evaluated with v. 

              outF= F(v)=    v[0]²+  v[1]² 

The user can apply other tensor and field operators on the cfexp including differentiation.
  ```
field #1(2)[2] GF = ∇F; 
tensor[] outGF = inst(GF,v);
 ```
The differentiation of the cfexp is computed in respect to the variable v. We illustrate the expected structure below:      

   outGF=  ∇F(v)
   =[2*v[0],2*v[1]]


A function can be defined with multiple variables.
                    F (a, b) = a + b 
and similarly a closed-form expression can be defined with multiple variables
  ```
real a = 1; real b = 7;  
tensor [] exp = a+b;  
field#k(d)[] G = cfexp(exp,a); 
field#k(d)[] H = cfexp(exp,a,b); 
field#k(d)[] I = cfexp(exp,b);
 ```
While ``exp`` uses two variables we only probe the fields G, H, and I with the number of variables used in the field definition.
``` 
real x= 3; real y =4;
tensor[] GP = G(x); 
tensor[] HP = H(x,y); 
tensor[] IP = I(y);
 ```
	
Differentiation is applied in respect to all the field variables: 
∇ G= ∇ a              
∇ H= ∇ a +∇ b                       
∇ I=   ∇ b


There are two ways to define a field with a closed form expression:``cfexp()`` and ``expression()``.
The difference between ``cfexp()`` and ``expression()`` is that the variable arguments are treated as type tty or fty, respectively. 
The derivative of a tty variable is 0, while a fty variable is treated like a field.
With the function ``setDiffVar()`` individual variables can be set to fty, regardless of their order in the field definition.

Here is an example:
                    F (s, a, b) = s*(A²-B) 
  ```
tensor [] exp = s*(A²-B);  
field#k+1(d)[] F =   expression(exp, s, A B);  
field#k(d)[] K = ∇(setDiffVar(F,A));   //Takes derivative in respect to A
field#k(d)[] L = ∇(setDiffVar(F,B));   //Takes derivative in respect to B
field#k(d)[] M = ∇(setDiffVar(setDiffVar(F,A),B));  //Takes derivative in respect to A and B 
 ```
The code does the following computations:  
F = exp = s*(A²-B)              
K = ∇<sub>A</sub> exp = ∇<sub>A</sub>  s*(A²-B) = s*2*a                      
L = ∇<sub>B</sub> exp = ∇<sub>B</sub>  s*(A²-B)=   -s       
M = ∇<sub>AB</sub> exp = ∇<sub>AB</sub> s*(A²-B)= s*(2*A -1)


As a shorthand function `cfexpOne()` sets the first variable to tty and next two as fty.   
```
field#k(d)[]M = ∇(cfexpOne(exp, s, A, B));  
// The above is the same as below   
field#k(d)[]M= ∇(setDiffVar(setDiffVar(F,A),B));   
```
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “cfexp()"
	- Declare a closed form expression with cfexp(exp,v) and evaluate it with “inst()”
	* “exp” is the core computation that includes operators on and between variables 
	* “v” is the variable we differentiate in respect to. We accept 1-3 “v” terms  
	* cfexp(): tensor[α] × tensor[β] . . . → field#k(d)[α]  
	* expression(): tensor[α] × tensor[β1]× tensor[β2]× tensor[β3] → field#k(d)[α]  
	* cfexpOne():   tensor[α] × tensor[β1]× tensor[β2]× tensor[β3] → field#k(d)[α]  
	* inst(): field#k(d)[α] × tensor[β] · · · → tensor[α]
* Text: see [Doc]
* Issues:  
	* Need to define all variables and initiate with unique values before cfexp() is called. 
	* Variables are also a tensor type? Retink that?
	* Field type doesn’t describe types for multiple inputs, need to change typechecker, Remove k-continuity 

## Directory Organization
* One input variable that has to be vector the length of the field dimension shown in directory : X1-X4, X6
* Multiple variables are in the core computation and we differentiate in respect to multiple variables  
	* [f<sub>sv</sub> = s ∗ v] : X5/m1.diderot, 
	* [f<sub>svx</sub> = s ∗ v + x] : X5/m2.diderot, and
	*  [f<sub>abc</sub> = a³bc²] : X5/m3.diderot
* Input variables are treated as tensors and fields  : X10, X11	
## Note to future developers
* Everything inside CFExp needs to be written in EIN (because of substitution process)
* DATm tested cfexp in combination with all tensor operators. Sympy does not support product rule so that wasn't as agressively tested 
* Tensor variable argument is the pair (param_id, tty/fty) 
