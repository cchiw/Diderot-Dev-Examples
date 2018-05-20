# Field Definition: Closed Form expression

Users can define closed form expressions. The expression can include tensor operators and variables.  Differentiation is applied by differentiating in respect to one variable.
	
## In Action
It is natural to define a function with an expression: F(x) = x²
 ```  
field#k(2)[] F(x) = x*x;
tensor[2] v = [3,7];  
tensor[] out = F(v);//evaluate F with argument v
 ```
 	> *Note* variable x is a vector of length d, where d is the dimension of the field.

              out= F(v)=    v[0]²+  v[1]² 

The user can apply other tensor and field operators on the cfexp including differentiation.
  ```
tensor[2] out = ∇F(v);
 ```
The differentiation of the cfexp is computed in respect to the variable v. We illustrate the expected structure below:      

   out=  ∇F(v)
   =[2*v[0],2*v[1]]

## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “field#k(d)[alpha](var) = expression"
	* “exp” is the core computation that includes operators on variable var 
	* “var” is a vector of length d
* Text: see [Doc]
* Issues:  Very limiting. See other directory 

## Directory Organization
* Base Case Examples
	*  [f<sub>v</sub> = v] : X1, 
	* [f<sub>v</sub> = v • v] : X1/vv.diderot,
	*  [f<sub>v</sub> = (v • v) ∗ v] : X1/vvv.diderot, and 
	* [f<sub>s</sub> = s³] : X2/sss.diderot
	* [f<sub>v</sub> = v • v] : X1/vv.diderot,
	* [f<sub>v</sub> =  ∇• v] Divergence : X7
* Multiple variables in core computation and differentiate in respect to one variable
	*  [f<sub>x</sub> =(1−|x|)⁴]Sphere: X3/sphere.diderot,
	*  [f<sub>x</sub> =(x−cutPos)•curNorm] clip: X3
	*  [f<sub>x</sub>= ( 1 ∗ (1 − |x| ))³] Circle : X4, and 
	* [f<sub>x</sub> = (1 − |x|/y)⁴	] Enr : X4/enr.diderot
	* X5
