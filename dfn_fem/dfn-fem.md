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
To represent a 3-d scalar field we would augment the previous code as
```
input fem#4(3)[] FF0;
mesh M = UnitCubeMesh(4,4,4)
```
To define a vector field of length 3 we would use a TensorFunctionSpace() and make the following changes:
```
input fem#4(3)[3] FF0;
fnspace VF0 = TensorFunctionSpace(M, E, polyorder,{3});
```
To accommodate a second-order tensor field we augment the shape parameter.
```
input fem#4(3)[3, 3] FF1;
fnspace VF1 = TensorFunctionSpace(M, E, polyorder,{3,3});
```
**Define a Mesh**
UnitSquareMesh():  int ×  int   → *mesh*
UnitCubeMesh(): int ×  int  × int     → *mesh*
**Define a Element**
Lagrange():   →*element*
P():   → *element*
**Define a Function Space**
FunctionSpace(): *mesh* × *element*  × int →*fnspace*
TensorFunctionSpace(): *mesh* × *element*  × int × int sequence→*fnspace*
**Define a ofield with fem data**
convert(): *fem#k(d)[α]* × string    →ofield#k(d)[α] 
convert(): *fem#k(d)[α]* × *fnspace* × string    →ofield#k(d)[α] 
### Other operations on ofield
**Inside Test**
insideF(): tensor[d]×ofield#k(d)[α] →boolean
**Probe**
inst(): tensor[d]×ofield#k(d)[α] → tensor[α]
**GetCell()**: Get the cell number the point is located in

## Details

* Branch: [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: “see summary above"
* Text: none

## Directory Organization

* Gradient of a field (2-d, Scalar, Unit Square Mesh, element P)  : X1
* ^ (3-d, Scalar, Unit Cube Mesh, Lagrange): X2
* Inner product between vector field and second order tensor field (3-d): X3
