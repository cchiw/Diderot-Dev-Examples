# Math functions: GetCell()
## In Action
A user can define a FEM field : [dfn_fem](https://github.com/cchiw/latte/tree/master/dfn_fem "dfn_fem").  This type of field is created with a mesh, reference element, and other relevant FEM data. 
``` 
input fem#1(2)[] f;
fnspace V = FunctionSpace(UnitSquareMesh(2,2), Lagrange(), 2);
string path = "/Users/chariseechiw/diderot/Diderot-Dev/fnspace_data/";
ofield#1(2)[] F = convert(f, V, path)
```
When the field is probed at a position than the compiler has find the right cell the position is located in. The surface level operator ``GetCell()`` allows the user to get the cell number for a position in a FEM field.
```
int currentcell = GetCell(F,pos);  
```

### Syntax Summary
  * **Inside** Check if a position is inside a field-``insideF()``: tensor[d]×ofield#k(d)[α] →boolean
  * **Probe**  Probe the field at a position-``inst()``: tensor[d]×ofield#k(d)[α] → tensor[α]
  *  **GetCell**  Get the cell number the point is located in-``GetCell()``: tensor[d]×ofield#k(d)[α] →  int
  *  **Define FEM** Defining a FEM field: [dfn_fem](https://github.com/cchiw/latte/tree/master/dfn_fem "dfn_fem").
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “GetCell"  field#k(d)[α] × tensor[d] →int
* Notes- When there is no Cell the function returns -1.
## Directory Organization
Examples: X1


