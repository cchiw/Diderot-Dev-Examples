# Tool: Printing the intermediate representation
Translate our compiler's intermediate representation (EIN) into a readable latex or unicode format.	
## In Action
Derivations by hand can be tedious and error-prone. To address that issue we support a higher-order notation.  For instance, consider the following Diderot code
 ```  
image(2)[] a;				image(2)[] b;
field#4(2)[]A = a⊛u;		field#4(2)[]B = b⊛v;
field#4(2)[]G = (A*V)/B;
output tensor[3] out =  ∇⊗(G)(pos);
 ```
 > *Note* that that the image type is defined separately. These are the variable names that will be used when printing out the IR.
The differentiation operations ∇⊗∇ are distributed across the tensor operations defined in filed type G. Internally, Diderot's rewriting system applies tensor calculus based rewrites that will distribute the differentiation operation. 

**Type of rewrite**  The user has to use command "--readEinRewrite" or "--readEin*", where * is a number from 1 -4.
The user can print out the intermediate representation after the rewriting stage with command line arguments:
> Diderot-Dev/bin/diderotc --readEin3 --readEinUni T.diderot
> (divide{((a*∇⊗v)+((v⊗∇a)))}{b}-divide{(a*(v⊗∇b))}{((b)^2)})

To see multiple rewriting options we can use command --readEinRewrite:
> Diderot-Dev/bin/diderotc --readEinRewrite --readEinUni T.diderot
> flat	->(divide{-((a*(v⊗∇b)))}{((b)^2)}+divide{(a*∇⊗v)}{b}+divide{((v⊗∇a))}{b})
> match	->(divide{-((a*(v⊗∇b)))}{((b)^2)}+divide{(a*∇⊗v)}{b}+divide{((v⊗∇a))}{b})
> refactor	->(divide{((a*∇⊗v)+((v⊗∇a)))}{b}-divide{(a*(v⊗∇b))}{((b)^2)})
> pull-division	->(((a*∇⊗v)+((v⊗∇a)))*divide{1}{b}-(a*(v⊗∇b))*divide{1}{((b)^2)}) 

>*Note* There are four rewriting options listed above. The best output can vary by computation. The user can compile the program again and specify a particular rewrite with the command "--readEin" followed by the rewrite number. Thus the command "--readEin3" printed the third rewrite.

**Optional Commands** The use can specificy a format (latex or unicode) and output (to terminal or saved to a file). See Details


## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Run: runs with command line flags 
	* Rewrite call(required)
		* --readEinRewrite : print four steps of rewriting
		* --readEin1, --readEin2, --readEin3, --readEin4: specify a single step of rewriting
	* Format(optional)
		* --readEinLatex : latex output 
		* --readEinUni : unicode output
		* By default both are used
	* Output Stream(optional)
		* --readEinPDF:  Save to text file 
		* By default prints to terminal
* Issues/Future Work
	*  pull out of strands
	* image types needs to be defined separately so we have a unique variable to refer to
	
## Directory Organization
* PVO Example in X1
	
