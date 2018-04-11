# Math functions: GetCell()
## In Action
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


## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: 
	* **Inside** Check if a position is inside a field-``insideF()``: tensor[d]×field#k(d)[α] →boolean
  	*  **GetCell**  Get the cell number the point is located in-``GetCell()``: field#k(d)[α] ×tensor[d]× →  int 
	
	When there is no Cell the function returns -1.
* Notes: Defining a FEM field: [dfn_fem](https://github.com/cchiw/latte/tree/master/dfn_fem "dfn_fem").


## Directory Organization
Examples: X1



