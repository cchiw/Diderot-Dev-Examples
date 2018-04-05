# Tool: Printing the intermediate representation
Translate our compiler's intermediate representation (EIN) into a readable latex or unicode format.	
## In Action
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
In leui of using the ```printIR()``` operation the user can use command line argument "--readEin". It will print a larger portion of the computations in the program (every EIN operator in the high-to-mid stage of the compiler).

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
	
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: printIR
* Run: runs with command line flags and surface level operator 
* Issues/Future Work
	*  pull out of strands
	* image types needs to be defined separately so we have a unique variable to refer to
	
## Directory Organization
* PVO Example in X1
* Another Example in X2
* Example using surface level operator ```printIR``` in X3
	
