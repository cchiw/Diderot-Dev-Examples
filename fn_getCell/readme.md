# Math functions: GetCell()
## In Action
A user can define a field as a structure composed of    a mesh, reference element, and PDE solution.  The code to define this type of field is copied below but check out the relevant directory [dfn_fem](https://github.com/cchiw/latte/tree/master/dfn_fem "dfn_fem") for more details.
``` 
input fem#1(2)[] f;
fnspace V = FunctionSpace(UnitSquareMesh(2,2), Lagrange(), 2);
string path = "Diderot-Dev/fnspace_data/";
ofield#1(2)[] F = convert(f, V, path)
```
When this type of  field is probed at a position than the compiler has find the right cell the position is located in. The surface level operator ``GetCell()`` allows the user to get the cell number for a position in a FEM field
```
int currentcell = GetCell(F,pos);  
```
or more generally do an inside test that will return a boolean result
```
bool TF = insideF(pos,F);  
```
The user probes the FEM field at a position with 
```
tensor[] out = inst(F,pos);  
```

### Syntax Summary
  * **Inside** Check if a position is inside a field-``insideF()``: tensor[d]×ofield#k(d)[α] →boolean
  * **Probe**  Probe the field at a position-``inst()``: ofield#k(d)[α] ×tensor[d]→ tensor[α]
  *  **GetCell**  Get the cell number the point is located in-``GetCell()``: ofield#k(d)[α] ×tensor[d]× →  int
  *  **Define FEM** Defining a FEM field: [dfn_fem](https://github.com/cchiw/latte/tree/master/dfn_fem "dfn_fem").
  
### Run
* Change path to Diderot-Dev compiler in  data/makedefs.gmk and in the relevant diderot program
* Install  [Firedrake](https://www.firedrakeproject.org/download.html "Firedrake") and activate with 
	 > source firedrake/bin/activate
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “GetCell"  field#k(d)[α] × tensor[d] →int
* Notes- When there is no Cell the function returns -1.

## Directory Organization
Examples: X1
>Note:  To run examples change path 


