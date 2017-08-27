#  Design, Implementation, and Testing of new language features for Diderot
## Wish list
* Concatenation of fields     ex. f = comp(f0,f1)
* Composition of fields	      ex. f= f0◦f1
* Definine fields as polys    ex. f = x^2+y^2
* Constructive Solid Geometry ex. f= max(f0,f1)
* Clamp
* Define field with if/else statement
* Radial Basis functions    ex. f (x_i, σ) = Σ_i ϕ{|x-xi|;σ}
* Define field by shifting  ex. f = g(x+p(x))

## Organization of Directories
*  Organized by topic (comp/concat/maxmin/polys/other)
	- In each directory 
		* description of the implementation in "paper.pdf" 
		* DATm found bugs  and we save examples as regression tests in directories with the name ""X*"
	- Composition of fields in  "comp/"
	-  Concatenation of fields  in "concat/"
	- Lerp/Clerp/Clamp  in "other/"	
	- Defining fields as polynomials in "polys/"	
	- Max/Min/Abs  in  "maxmin/"
* Writeup of implementation and bugs found by DATm (writeup/paper.pdf)
* Nrrd files saved to ""data""
* dev directory is not ready to be viewed
* Fem has been moved to another repo.
