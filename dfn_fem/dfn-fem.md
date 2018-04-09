# Field Definition: FEM

Users can define fields created by outside tools

##  In Action
### Simple Definition
The user defines an input variable to represent a FEM field. The path included is a path to the relevant data file. 
```
input fem#k(d)[α] F0;
string path = "fnspace_data/data.json";
ofield#4(2)[] F = convert(F0, path);
```
The final term is an *ofield* type that acts the same as the Diderot *field* type.

### Include Function Space
The user can choose to define the field by describing the function space ``VF`` and by providing a path to a directory ``pathVF``.
```
input fem#k(d)[α] F0;
fnspace VF = ....
string pathVF = ...
ofield#4(2)[] F = convert(F0,VF,pathVF);
```
The variable  ``VF`` is a  *fnspace* type.  It is defined with a *mesh*, *element*,  and *int* (to indicate order of coefficients). The current options for a *mesh* are ``UnitCubeMesh()`` and ``UnitSquareMesh()``. An *element* type is an abstract representation of a reference element. It can be either   ``Lagrange()``  or ``P()``.  A *fnspace* type represents a function space. It can be either    ``FunctionSpace()`` for scalars or ``TensorFunctionSpace()`` for non-scalars. 
The following is an example of a 2-d scalar field: 
```
input fem#k(2)[] F0;
mesh M = UnitSquareMesh(4,4);
element E = P();
int polyorder = 4;
fnspace VF = FunctionSpace(M,E,polyorder);
ofield#4(2)[] F = convert(F0,VF,pathVF);
```
To represent a 3-d scalar field the ``mesh`` and ``fem`` type need to be changed:
```
input fem#k(3)[] F0;
mesh M = UnitCubeMesh(4,4,4)
```
To define a vector field of length ``i`` use  ``TensorFunctionSpace()``:
```
input fem#k(3)[i] F0;
fnspace VF = TensorFunctionSpace(M, E, polyorder,{i});
```
To accommodate a second-order (``i,j``) tensor field augment the shape parameter:
```
input fem#k(3)[i, j] F0;
fnspace VF = TensorFunctionSpace(M, E, polyorder,{i,j});
```
### Sumary of syntax
* **Define a Mesh, Element, and Function Space**
  * Define a Unit Square Mesh- ``UnitSquareMesh()``:  int ×  int   → *mesh*
  * Define a Unit Cube Mesh- ``UnitCubeMesh()``: int ×  int  × int     → *mesh*
  * Define a Lagrange reference element- ``Lagrange()``:   →*element*
  * Define a P reference element- ``P()``:   → *element*
  * Define a function space for scalar fields- ``FunctionSpace()``: *mesh* × *element*  × int →*fnspace*
  * Define a function space for non-scalar fields- ``TensorFunctionSpace()``: *mesh* × *element*  × int × int sequence→*fnspace*
* **Define an ofield with fem data**
  * Define a fem field- ``convert()``: *fem#k(d)[α]* × string    →ofield#k(d)[α] 
  * Define a fem field with the function space-``convert()``: *fem#k(d)[α]* × *fnspace* × string    →ofield#k(d)[α] 
* **Other operations on ofield**
  * Check if a position is inside a field-``insideF()``: tensor[d]×ofield#k(d)[α] →boolean
  * Probe the field at a position-``inst()``: tensor[d]×ofield#k(d)[α] → tensor[α]
  * Get the cell number the point is located in-``GetCell()``: tensor[d]×ofield#k(d)[α] →  int 

## Details

* Branch: [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: “see summary above"
* Text: none

## Directory Organization

* Gradient of a field (2-d, Scalar, Unit Square Mesh, element P)  : X1
* ^ (3-d, Scalar, Unit Cube Mesh, Lagrange): X2
* Inner product between vector field and second order tensor field (3-d): X3
