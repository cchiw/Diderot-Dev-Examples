
# Overview of Repo
 - A. Functions and Operators
	 - A1. Function composition: [fn_composition](https://github.com/cchiw/latte/tree/master/fn_composition "fn_composition")
	 - A2. Function concatenation: [fn_concatenation](https://github.com/cchiw/latte/tree/master/fn_concatenation "fn_concatenation")
	 - A3. Matrix Inverse: [fn_matrixInverse](https://github.com/cchiw/latte/tree/master/fn_matrixInverse "fn_matrixInverse")
	 - A4. Min and Max: [fn_min-max](https://github.com/cchiw/latte/tree/master/fn_min-max "fn_min-max")
	 - A5. Clerp and Clamp: [fn_clerp](https://github.com/cchiw/latte/tree/master/fn_clerp "fn_clerp")
	 - A6. Field Selection: [fn_selection](https://github.com/cchiw/latte/tree/master/fn_selection "fn_selection")
	 - A7. Find Cell: [fn_getCell](https://github.com/cchiw/latte/tree/master/fn_getCell "fn_getCell")
- B. Tools
	- B1. DATm: Diderot’s Automated Testing: [tool_DATm](https://github.com/cchiw/latte/tree/master/tool_DATm "tool_DATm")
	- B2. Printing the intermediate representation: [tool_printIR](https://github.com/cchiw/latte/tree/master/tool_printIR "tool_printIR")
- C. Field Definitions
	- C1. Closed Form expressions: [dfn_cfe](https://github.com/cchiw/latte/tree/master/dfn_cfe "dfn_cfe")
	- C2. FEM: [dfn_fem](https://github.com/cchiw/latte/tree/master/dfn_fem "dfn_fem")

Please see individual directory for full details. They are summarized (or fully copied) below.

# A.Functions and Operators
## A1. Function composition
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

> field#k(d1)[α]× field#k(d0)[d1] → field#k(d1)[α]
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

### Details
* Branch: [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: "compose"  and "◦"
	- field#k(d1)[α]× field#k(d0)[d1] → field#k(d1)[α]
* Text: EIN IR design, rewriting rules, and resolved bugs listed in Doc
* Examples Directory : [fn_composition](https://github.com/cchiw/latte/tree/master/fn_composition "fn_composition")

----------
----------
## A2. Function concatenation
Given multiple fields
```
field#k(d)[α] A;  field#k(d)[α] B; field#k(d)[α] C;
```
A user might want to put two fields together to create a new field
```
field#k(d)[3,α] M = [A,B,C]
```
> **Note:** The field arguments must have the same type
### Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: ``[``,``]``
    - field#k(d)[α] × field#k(d)[α]× ....field#k(d)[α] → field#k(d)[n,α] where n is the number of arguments
* Syntax:``concat``
    - field#k(d)[α] × field#k(d)[α] → field#k(d)[2,α]
* Text: `concat` Mentioned in dissertation-FW. 

* Examples Directory: [fn_concatenation](https://github.com/cchiw/latte/tree/master/fn_concatenation "fn_concatenation")
----------
----------
## A3. Matrix Inverse
Given matrix M and a second order tensor field F
```
tensor[d,d] M;
field#k(d)[d,d] F;
```

A user can take the matrix inverse

```
tensor[d,d] MI = inv(M);
field#k(d)[d,d] FI = inv(F)
```

> **Note:** The two fields have the same type

### Details
* Branch: [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: “inv()”
	- field#k(d)[d,d] → field#k(d)[d,d]
	- tensor[n,n] → tensor[n,n]
* Text: Mentioned in dissertation-Design
----------
----------
## A4. Min and Max
Given two scalar fields 
```
tensor[] M;  
field#k(d)[] A;
field#k(d)[] B;
```
A user can compare them by taking the maximum and minimum 
```
field#k(d)[] F = Max(A,B);  
field#k(d)[] G = Min(A,B)
```
Then take the derivative 
```
field#k-1(d)[d] F = ∇ Max(A,B);  
```
### Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “Max” and "Min"
    -  field#k(d)[] ×  field#k(d)[] →  field#k(d)[]
* Examples Directory [fn_min-max](https://github.com/cchiw/latte/tree/master/fn_min-max "fn_min-max")
----------
----------
## A5. Clerp and Clamp

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

### Details
* Branch:  [Vis15](http://smlnj-gforge.cs.uchicago.edu/scm/viewvc.php/branches/vis15/?root=diderot) & [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: “clerp()” New Clerp function
	- tensor[i] × tensor[i] × real → tensor[i]
	- tensor[i] × tensor[i] × real × real × real → tensor[i]
* Syntax: “clamp()” Clamp function can be applied to general tensors
	- tty = tensor[α]
	- tty × tty × tty → tty
* Examples directory: [fn_clerp](https://github.com/cchiw/latte/tree/master/fn_clerp "fn_clerp")
----------
----------
## A6.Field Selection

Inside a Diderot program there may be many different field definitions and computations on those fields
```
field#k(d)[α] A; field#k(d)[α] B; field#k(d)[α] C;  field#k(d)[α] D;...
```
Typically, this meant that the Diderot programmer would comment some lines in and out and recompile when trying different definitions. To make it easier we created a new function "swap()" that alternates between different field definitions based on the *selection_id.*
```
int selection_id;
field#k(d)[] F = swap(selection_id,A,B,C,D);
```
As a note, the selection_id can also be an input variable.
```
input int selection_id;
```
### Details
* Branch: [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: “swap()"
	- fty = field#k(d)[α]
	- int × fty × fty → fty
	- int × fty × fty× .... → fty
	- int × fty × fty × fty × fty × fty × fty → fty
* Arguments
	- *Selection id* The first argument  is an integer that serves to select a field. i.e. id=2 chooses the second field argument
	- *Field arguments* The function accepts 2-6 field arguments.
* Potential issue:  The value of the *Selection id* is clamped. If the first argument is id=-7 the id is set to 1 instead of throwing an error
* Examples directory: [fn_selection](https://github.com/cchiw/latte/tree/master/fn_selection "fn_selection")


## A7. Math functions: GetCell()
A user can define a field created as the result of an outside tool.  The code to define this type of field is copied below
``` 
input fem#1(2)[] f;
field#1(2)[] F = FEM(f, "Diderot-Dev/fnspace_data/data.json")
```
but check out the relevant directory [dfn_fem](https://github.com/cchiw/latte/tree/master/dfn_fem "dfn_fem") for more details. When this type of  field is probed at a position then the right cell needs to be found. The surface level operator ``GetCell()`` allows the Diderot user to use that value in the Diderot program.
```
int currentcell = GetCell(F,pos);  
```
An inside test will return a boolean
```
bool TF = insideF(pos,F);  
```
The user probes the FEM field at a position with 
```
tensor[] out = F(pos);  
```
### Run
* Change path to Diderot-Dev compiler in  data/makedefs.gmk and in the relevant diderot program
* Install  [Firedrake](https://www.firedrakeproject.org/download.html "Firedrake") and activate with 
	 > source firedrake/bin/activate


### Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: 
	* **Inside** Check if a position is inside a field-``insideF()``: tensor[d]×field#k(d)[α] →boolean
  	*  **GetCell**  Get the cell number the point is located in-``GetCell()``: field#k(d)[α] ×tensor[d]× →  int 
	
	When there is no Cell the function returns -1.
* Notes: Defining a FEM field: [dfn_fem](https://github.com/cchiw/latte/tree/master/dfn_fem "dfn_fem").
* Examples directory: [fn_getCell](https://github.com/cchiw/latte/tree/master/fn_getCell "fn_getCell")

# B.Tools
## B1. DATm: Diderot's Automated Testing

* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Use: Test operators on and between tensors/image data based on correctness
* Tool: DATm:Diderot’s Automated Testing tool  
* Text:  [ICSE-AST paper](https://www.researchgate.net/publication/317836930_DATm_Diderot%27s_Automated_Testing_Model) and Testing chapter in [Dissertation](http://pl.cs.uchicago.edu/documents/chiw_dissertation.pdf)
	 > Testing environment variables in Pg 102 
	> Adding a new operator in Pg 113 
### Getting Started
Quick instructions
 1. Checkout github directory for [DATm](https://github.com/cchiw/DATm.git)
	 > git clone https://github.com/cchiw/DATm.git
 2.  Change cpath in Frame to your absolute path to diderot branches. See *Set Up* about other variables you might want to change.
    3.  Starting Testing with command line arguments. See Section on *Running DATm*.
		> python3 datm.py 

### Set Up:  variables and testing frame settings
Settings in the testing process can be changed by commenting in/out variables in the *Frame* (input.py).
* **Change branch**(s_branch) : 
Tell DATm the name of branch being tested. Some branch names are built in(vis15,Diderot-Dev, Chiw17). Comment in the right ```s_branch``` variable in Frame 
	```
	#s_branch  = branch_vis15
	s_branch = branch_dev 
	#s_branch = branch_chiw17
	#s_branch  = branch_other
	```
or comment in ``branch_other`` and set the variable to a string in *shared/base_constants.py*
    
* **Complexity** (s_layer):
The core computation in a Diderot test program can be simple or more complicated. s_layer indicates the number of operators to apply in a core computation. That number can be 1, 2, or 3.

*  **type of field**(c_pde_test) :
DATm test tensors and fields. The fields can either be made by **nrrd** files or by Firedrake (outside tool to solve **PDE** solutions). For an original Diderot Field types created with nrrd, set variable  ```c_pde_test``` to False in *Frame*. For PDE solutions set the variable to true and change the path in fem/makedefs.gmk.

* **type of search** (s_random_range)
For an **exhaustive testing** approach, set variable  ```s_random_range```  to 0 in *Frame*. For **randomized testing** set the variable to x  where the probability of a single test case being generated is  1  in x+1.

* **order of coefficients**(s_coeff_style) :
The order of coefficients for the polynomial creating synthetic data. The data can either be linear, quadratic or cubic.
	```
	#s_coeff_style = coeff_linear
	s_coeff_style = coeff_quadratic
	#s_coeff_style = coeff_cubic
	```

*  **testing environment:**
You can comment in and out variables in *Frame*. This includes variables to change the number of samples, type of arguments,..
	> More details in Pg 102 in [Dissertation](http://pl.cs.uchicago.edu/documents/chiw_dissertation.pdf),

### Labels
 * Each test case has a testing *label*
 	> Of the form "p_o1...l2"
### Running DATm: command-line commands and targetting testing
The testing environment is indicated by the *Frame*. The scope helps target a specific operator, test, or family of programs.
-   Run everything:
	> python3 datm.py
    
-   Test a single operator
	> python3 datm.py id # where id is a number
	> *Note* Each operator has a unique id. List printed to screen and copies to rst/stash/results_ops.txt
	
-  Family of computations         
	Rerun (group of) tests by using 1-4 integers from the testing *label*.
	For instance, the label
	
	> “p_o27_o0_t0_tN_tN_l2” 
	
	can rerun with command 
	
	> python datm.py 27 0 0 
	


###    Results passes/fails
Great, everything is running now, but how do I look at the results? In the directory rst/stash are several text files that record the test cases (with *labels*)
 * *results_final.txt*:The results of each test case 	
 * *results_terrible.txt:* Reports test cases with errors  
 * *results_ty.txt*:Test Types used
 * *results_ops.txt*:Operators with ids
### Development
* Adding a new operator to DATm:     
    1. Add to operator constant: *shared/obj_operator.py* 
    2. Add case to type-checker: *shared/obj_typechecker.py*
    3. Add way to evaluate that operator applied to polynomials: *nc/nc_eval.py*
   > More details in Pg 113 in  [Dissertation](http://pl.cs.uchicago.edu/documents/chiw_dissertation.pdf)



## B2. Printing the intermediate representation
Translate our compiler's intermediate representation (EIN) into a readable latex or unicode format.	

Derivations by hand can be tedious and error-prone. To address that issue we support a higher-order notation.  For instance, consider the following Diderot code
 ```  
image(2)[] a;				image(2)[] b;
field#4(3)[]A =k⊛ a; 			field#4(3)[]B =k⊛ b;f		field#4(3)[3]V =k⊛v;
field#3(3)[3]G =  (A*V)/B;
tensor[3,3] T =  (∇⊗G)(pos);
```
 > *Note* that that the image type is defined separately. These are the variable names that will be used when printing out the IR.
 
The differentiation operations ∇⊗∇ are distributed across the tensor operations defined in filed type G. Internally, Diderot's rewriting system applies tensor calculus based rewrites that will distribute the differentiation operation. 
There are two ways to print out the intermediate representation: a surface level operator and with a command line argument.
In both cases the user can use command line arguments to make specific formatting and rewriting choices.

### Specify a single computation to print
We can use the operation ```printIR()``` to print a specific computation on the command line
```
output int out =  printIR(T);
```
or save the output to a text file "tmpRead"
```
output int out =  printIR(T,"tmpRead");
```
By default the tool will save one version of the IR in two files: Unicode in "tmpRead.txt" and latex version in tmpRead.latex. 

### Print whatever we can
In lieu of using the ```printIR()``` operation the user can use command line argument "--readEin". It will print a larger portion of the computations in the program (every EIN operator in the high-to-mid stage of the compiler).

### Command Line Arguments
* *Format*
	* (default)		: both latex and unicode output
	* --formatTex	        : latex output only
	* --formatUni 		: unicode output only
* *Representation*
	* (default)		: surface level representation (without indices)
	* --repEin	        : EIN notation only
	* --repMultiple           : Four variations of the computations in surface level representation
* *Output*
	* (default)		: print to terminal
	* --savePDF		: Save to file "output_tmp" 
	
### Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: printIR
* Run: runs with command line flags and surface level operator 
* Issues/Future Work
	*  pull out of strands
	* image types needs to be defined separately so we have a unique variable to refer to
	
	
	
	
# C. Field Definitions
## C1. Field Definition: Closed Form expression


Users can define closed form expressions. The expression can include tensor operators and variables.  Differentiation is applied by differentiating in respect to some variable(s).
	
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


As a shorthand function`cfexpOne()` sets the first variable to tty and next two as fty.   
```
field#k(d)[]M = ∇(cfexpOne(exp, s, A, B));  
// The above is the same as below   
field#k(d)[]M= ∇(setDiffVar(setDiffVar(F,A),B));   
```
### Details
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
* Examples in directory [dfn_cfe](https://github.com/cchiw/latte/tree/master/dfn_cfe "dfn_cfe")


## C2. FEM

# Field Definition: FEM
We support computations on fields defined by outside sources.
##  In Action
There are four steps to the implementation process: 
 1. Diderot code (observ.diderot) 
 2. C code that communicates to the generated Diderot code   (observ_init.c) 
 3. Python code that initiates the C code and creates FEM data (observ.py)
 4. Running the program (run.sh)

For the most part steps 2-4 are the same for each example and code can be easily reused. 

### 1.Diderot Code (observ.diderot)
The user declares a FEM field with the function``FEM`` and two arguments. The first argument is an input variable and the second is a path to the relevant data file.
```
input fem#k(d)[α] F0;
field#k(d)[α] F = FEM(F0, "data.json");
```
Define a fem field- ``FEM()``: *fem#k(d)[α]* × string    →field#k(d)[α] 


### 2. C code that communicates to the generated Diderot code (observ_init.c)
The C code is used to communicate with the generated Diderot code. The function ```callDiderot_observ()``` can be called by outside tools.
```
void callDiderot_observ(char *Outfile, void *valF)
```
The function takes the name of the output nrrd file and a pointer to the field data.

Otherwise, the code here is FEM independent and does not need augmentation.
.....

### 4. Running the whole thing (run.sh)
* Change path to Diderot-Dev compiler in  data/makedefs.gmk and in the relevant diderot program
* Install  [Firedrake](https://www.firedrakeproject.org/download.html "Firedrake") and activate with 
	 > source firedrake/bin/activate
* Make and run
	> python observ.py

* Branch: [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Read full readme file in [dfn_fem](https://github.com/cchiw/latte/tree/master/dfn_fem "dfn_fem")


