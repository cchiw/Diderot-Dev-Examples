# Field Definition: Closed Form expression

Users can define closed form expressions. The expression can include tensor operators and variables.  Differentiation is applied by differentiating in respect to some variable(s).
	
## In Action
It is natural to define a function with an expression: F(x) = x²
In the surface language we added function cfexp() where the first argument exp is an expression and the second x is a variable.
 ``` 
tensor [] exp = x*x;  
ofield#2(2)[] F = cfexp(exp,x);//define F with variable x 
tensor[2] v = [3,7];  
tensor[] outF = inst(F,v);//evaluate F with argument v
 ```
We commonly refer to the right-hand-side to variable F as a cfexp (closed-form expression). The cfe is created with variable x, but is actually evaluated with v. 

              outF= F(v)=    v[0]²+  v[1]² 

The cfexp is a Diderot “ofield” type, but is treated the same as a Diderot "field type". The user can apply other tensor and field operators on the cfexp including differentiation.
  ```
ofield #1(2)[2] GF = ∇F; 
tensor[] outGF = inst(GF,v);
 ```
The differentiation of the cfexp is computed in respect to the variable v. We illustrate the expected structure below:      

   outGF=  ∇F(v)
   =[2*v[0],2*v[1]]


A function can be defined with multiple variables.
                    F (a, b) = a + b 
and similarly a cfexp can be defined with multiple variables
  ```
real[] a = 1; real b = 7;  
tensor [] exp = a+b;  
ofield#k(d)[] G = cfexp(exp,a); 
ofield#k(d)[] H = cfexp(exp,a,b); 
ofield#k(d)[] I = cfexp(exp,b);
 ```
The distinction between G, H, and I is that differentiation is applied in respect to either one or two variables.

∇G<sub>a</sub>= ∇ a +b               
∇H<sub>ab</sub>= ∇ a +∇ b                       
∇I<sub>b</sub>=   a +∇ b

## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “cfexp()"
	- Use an ofield type ofield#k(d)[β], which is the same as a Diderot field but has an "o" in  front of it.
	- Declare a closed form expression with cfexp(exp,v) and evaluate that oField with “inst()”
	* “exp” is the core computation that includes operators on and between variables 
	* “v” is the variable we differentiate in respect to. We accept 1-3 “v” terms  
	* cfexp(): tensor[α] × tensor[β] . . . → ofield#k(d)[α]  
	* inst(): ofield#k(d)[α] × tensor[β] · · · → tensor[α]
* Text: see [Doc]
* Issues:  
	* Need to define/initiate all variables before cfexp() is called.  
* Syntax:  
	* OField type doesn’t describe types for multiple inputs, need to change typechecker, Remove k-continuity 
* Testing:
	* DATm tested cfexp incombination with all tensor operators
	* Sympy does not support product rule. So those tests had to be made by hand
## Directory Organization
* Base Case Examples
	*   [f<sub>v</sub> = v] : X1/v.diderot, 
	* [f<sub>v</sub> = v • v] : X1/vv.diderot,
	*  [f<sub>v</sub> = (v • v) ∗ v] : X1/vvv.diderot, and 
	* [f<sub>s</sub> = s³] : X2/sss.diderot
* Multiple variables in core computation and differentiate in respect to one variable
	*  [f<sub>x</sub> =(1−|x|)⁴]Sphere: X3/sphere.diderot,
	*  [f<sub>x</sub> =(x−cutPos)•curNorm] clip: X3/clip.diderot,
	*  [f<sub>x</sub>= ( 1 ∗ (1 − |x| ))³] Circle : X4/circle.diderot, and 
	* [f<sub>x</sub> = (1 − |x|/y)⁴	] Enr : X4/enr.diderot
* Multiple variables are in the core computation and we differentiate in respect to multiple variables  
	* [f<sub>sv</sub> = s ∗ v] : X5/m1.diderot, 
	* [f<sub>svx</sub> = s ∗ v + x] : X5/m2.diderot, and
	*  [f<sub>abc</sub> = a³bc²] : X5/m3.diderot
	
## Note to future developers
* Everything inside CFExp needs to be written in EIN (because of substitution process)
* Should every expression be a tensor type? Should they support the application of field operators. Type Checking issue?field#3(2)[]GCFE = cfexp(compose(F0,F1*0.1),x,y);
