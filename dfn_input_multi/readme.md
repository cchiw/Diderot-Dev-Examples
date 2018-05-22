## Field Definition: Closed Form expression - Multiple Input

Users can define closed form expressions. The expression can include tensor operators and variables.  Differentiation is applied by differentiating in respect to some variable(s).
	
### In Action
A function can be defined with multiple variables.
                    F (a, b) = a + b 
and similarly a field can be defined with multiple input variables
  ```  
type F (real a, real b) = a+b; 
 ```
The ```type``` is an ofield Dideot type. The dimension is a list of vector sizes for the corresponding input variables. 

	>   ofield#k(d1,...dn)[α] (tensor[d1] ×...× tensor[dn])→ ofield#k(d1,...dn)[α]  
	
Differentiation is applied in respect to all the variables indicated between "(" ")": 
            ∇ F= ∇ a +∇ b                       
Alternatively, to indicate some input variables as constant variables (differentiation of it is 0) use a second pair parathesis.
  ```  
type G (real a)(real b) = exp; // takes derivative of exp in respect to a 
type I (real b)(real a) = exp; // takes derivative of exp in respect to b
type F (real a, real b) = exp; // takes derivative of exp in respect to a and b 
 ```
 

Here is an example:
                    F (s, a, b) = s*(A²-B) 
  ```
ofield#k(1,1,1)[] K = (real A)(real B, real S) = s*(A²-B);  //takes derivative in respect to A
ofield#k(1,1,1)[] L = (real B)(real A real S) =s*(A²-B)     //takes derivative in respect to B
ofield#k(1,1,1)[] M = (real A, real B)(real S) =s*(A²-B)    //takes derivative in respect to A and B 
 ```
The code does the following computations:              
∇K = ∇<sub>A</sub>  s*(A²-B) = ∇<sub>A</sub>  s*(A²-B) = s*2*a                      
∇L = ∇<sub>B</sub>  s*(A²-B) = ∇<sub>B</sub>  s*(A²-B)=   -s       
∇M = ∇<sub>AB</sub>  s*(A²-B) = ∇<sub>AB</sub> s*(A²-B)= s*(2*A -1)

   

### Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: 
	*  ofield#k(d1,...dn)[α] (tensor[d1] ×...× tensor[dn])→ ofield#k(d1,...dn)[α]  
	*  ofield#k(d1,...dn)[α] (tensor[d1] ×tensor[di]) (tensor[di+1]×...× tensor[dn])→ ofield#k(d1,d2,...dn)[α]  
* Issues:  
	* Using ofield here instead of field. Need to generalize field type or add new basis-vars.
	
### Directory Organization
Multiple variables are in the core computation 
* X1
* X2
* X3
	
## Note to future developers
* Everything inside CFExp needs to be written in EIN (because of substitution process)
* DATm tested cfexp in combination with all tensor operators. Sympy does not support product rule so that wasn't as agressively tested 
* Tensor variable argument is the pair (param_id, tty/fty) 
