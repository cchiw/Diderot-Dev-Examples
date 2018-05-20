# Field Definition: Closed Form expression

Users can define closed form expressions. The expression can include tensor operators and variables.  Differentiation is applied by differentiating in respect to one variable.
	
## In Action
It is natural to define a function with a closed form expression: F(x) = 7٭x. We allow a user to define such a field in Diderot
 ```  
field#k(d)[d] F(x) = 7٭x;
tensor[d] v =...;
tensor[d] out = F(v);
tensor[d,d] jacob = ∇⊗F(v)
tensor[] divergence = ∇•F(v)
 ```
> *Note* that variable x is a vector of length d, where d is the dimension of the field.

The probed field is evaluated as  

F(x) ⇨7٭x  ⇨ 7*[x<sub>a </sub>, x<sub>b </sub>,..x<sub>d </sub>]]  where x = [x<sub>a </sub>, x<sub>  b</sub>,..x<sub>d </sub>]

If v = [3,5] then F(v) =  [21, 35]

The user can apply other tensor and field operators on the field term `F` including differentiation. The Jacobian of our field `F` creates the following matrix.

∇⊗F(x) ⇨∇⊗(7٭x) ⇨ [[7,0],[0,7]]

and the divergence creates the following

∇•F(x) ⇨∇•(7٭x) ⇨ 14

Differentiation is applied to the entire expression on the right hand side of the field definition `F` and in respect to the variable `x`. Internally, The tensor variable `x` is expanded into it's components and  the differentiation operator is applied to the components.

∇⊗F(x)⇨ [[∇<sub>a </sub> 7*x<sub>a </sub>, ∇<sub>a </sub> 7*x<sub>b </sub>], [∇<sub>b </sub> 7*x<sub>a </sub>,∇<sub>b </sub> 7*x<sub>b </sub>]]




## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “field#k(d)[alpha](var) = expression"
	* “exp” is the core computation that includes operators on variable var 
	* “var” is a vector of length d
* Text: see [Doc]
* Issues:  Very limiting. See other directory 

## Directory Organization
* Base Case Examples
	*  [f<sub>v</sub> = 7*v] : X1, 
	* [f<sub>v</sub> = v • v] : X1/vv.diderot,
	*  [f<sub>v</sub> = (v • v) ∗ v] : X1/vvv.diderot, and 
	* [f<sub>s</sub> = s³] : X2
	* [f<sub>v</sub> =  ∇• v] Divergence : X7
* Multiple variables in core computation and differentiate in respect to one variable
	*  [f<sub>x</sub> =(1−|x|)⁴]Sphere: X3/sphere.diderot,
	*  [f<sub>x</sub> =(x−cutPos)•curNorm] clip: X3
	*  [f<sub>x</sub>= ( 1 ∗ (1 − |x| ))³] Circle : X4, and 
	* [f<sub>x</sub> = (1 − |x|/y)⁴	] Enr : X4/enr.diderot
	* X5
