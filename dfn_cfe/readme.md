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
and similarly a cfexp can be defined with multiple variables
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
	 
The distinction between G, H, and I is that differentiation is applied in respect to either one or two variables. 
∇<sub>a</sub>G= ∇ a              
∇<sub>ab</sub> H= ∇ a +∇ b                       
∇<sub>b</sub> I=   ∇ b

 
Note that with ``cfexp`` all variables are treated as fields. 
To provide more options we created  ``cfexpOne`` and ``cfexpTwo``, which both take three variables.
With ``cfexpOne`` the first variable is treated as a tensor. 
With ``cfexpTwo`` the first two variables are treated as a tensor. 

Here is a more interesting example:
                    F (s, a, b) = s*r*(A²-B) 
  ```
real r = 2; real s=...
tensor [] exp = s*r*(A²-B);  
field#k+1(d)[] J =   cfexpTwo(exp, s, B, A)); 
field#k(d)[] K = ∇(cfexpTwo(exp, s ,B, A)); 
field#k(d)[] L = ∇(cfexpTwo(exp, s, A, B));
field#k(d)[] M = ∇(cfexpOne(exp, s, A, B));
 ```
The code does the following computations:  
J = exp = s*r*(A²-B)              
K = ∇<sub>A</sub> exp = ∇<sub>A</sub>  s*r*(A²-B) = s*r*2*a                      
L = ∇<sub>B</sub> exp = ∇<sub>B</sub>  s*r*(A²-B)=   -s*r       
M = ∇<sub>AB</sub> exp = ∇<sub>AB</sub> s*r*(A²-B)= s*r*(2*A -1)

## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “cfexp()"
	- Declare a closed form expression with cfexp(exp,v) and evaluate it with “inst()”
	* “exp” is the core computation that includes operators on and between variables 
	* “v” is the variable we differentiate in respect to. We accept 1-3 “v” terms  
	* cfexp(): tensor[α] × tensor[β] . . . → field#k(d)[α]  
	* inst(): field#k(d)[α] × tensor[β] · · · → tensor[α]
* Text: see [Doc]
* Issues:  
	* Need to define all variables and initiate with unique values before cfexp() is called. 
	* Variables are also a tensor type? Retink that?
	* Field type doesn’t describe types for multiple inputs, need to change typechecker, Remove k-continuity 
* Testing:
	* DATm tested cfexp in combination with all tensor operators. Sympy does not support product rule so thatw wasn't as agressively tested (examples included use differentiation). 
## Directory Organization
* Base Case Examples
	*  [f<sub>v</sub> = v] : X1/v.diderot, 
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
* Expression had multiple tensor operstors applied to it : X7
* Expression is a large polynomial. Afterwards multiple operators applied to it : X8, X9	
* Input variables are treated as tensors and fields  : X10	
## Note to future developers
* Everything inside CFExp needs to be written in EIN (because of substitution process)

