
#  Design, Implementation, and Testing of new language features
## New Language features
* We add new field operators such as 
	- Composition of fields
	- Concatenation of fields 
	- Max/Min/Abs 
* We create other ways to define fields
	- Defining fields as polynomials
	- fem 
		- see diderot_fem on github for more complete examples
		- femprime branch
* Add support for new and generic versions of tensor operators
	-  Lerp/Clerp/Clamp 


##Organization of Directories
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