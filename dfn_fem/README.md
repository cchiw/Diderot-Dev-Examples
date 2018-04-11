# Field Definition: FEM
We support computations on fields defined by outside sources.
##  In Action
There are four steps to the implementation process: 
 - 1. Diderot code (observ.diderot) 
 - 2. C code that communicates to the generated Diderot code   (observ_init.c) 
 - 3. Python code that initiates the C code and creates FEM data (observ.py)
 - 4. Running the program (run.sh)

For the most part steps 2-4 are the same for each example and code can be easily reused. 

### 1.Diderot Code (observ.diderot)
#### Simple Definition
The user defines an input variable to represent a FEM field. The path included is a path to the relevant data file. 
```
input fem#k(d)[α] F0;
string path = "fnspace_data/data.json";
ofield#4(2)[] F = convert(F0, path);
```
The final term is an *ofield* type that acts the same as the Diderot *field* type.

#### Include Function Space
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
#### Sumary of syntax
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
* **Other operations on ofield**  Copied from [fn_getCell](https://github.com/cchiw/latte/tree/master/fn_getCell 'fn_getCell')
  	* **Inside** Check if a position is inside a field-``insideF()``: tensor[d]×ofield#k(d)[α] →boolean
  	* **Probe**  Probe the field at a position-``inst()``: ofield#k(d)[α] ×tensor[d]→ tensor[α]
  	*  **GetCell**  Get the cell number the point is located in-``GetCell()``: ofield#k(d)[α] ×tensor[d]× →  int* 

### 2. C code that communicates to the generated Diderot code (observ_init.c)
The C code is used to communicate with the generated Diderot code. The function ```callDiderot_observ()``` can be called by outside tools.
```
void callDiderot_observ(char *Outfile, void *valF)
```
The function takes the name of the output nrrd file and a pointer to the field data.

Otherwise, the code here is FEM independent and does not need augmentation.

### 3. Python code that initiates the C Code (observ.py)
The python code is used to create the fem field data. Otherwise, the  code can be used verbatim. 

It is necessary to have files *init.py **makejson.py* included in the path. Currently saved to the dfn_fem/data.
```
sys.path.insert(0, '../data/') #path to init.py, makejson.py
from init import *
from makejson import *
```
The field is defined by an outside source, such as Firedrake.The field could be the solution to a pde equation or the result of interpolating an expression over a function space:
```
from firedrake import *
.....
f0 = Function(V).interpolate(Expression(expf0))
```
After defining the field ``f0`` the following code is used to pass the field to Diderot. 
```
data = organizeData(f)
_call = ctypes.CDLL('observ_init.so') 
```
> *Note* 'observ_init.so' is the name of Diderot init program created.
```
_call.callDiderot_observ.argtypes =(ctypes.c_char_p,ctypes.c_void_p) #argument types
result =_call.callDiderot_observ(ctypes.c_char_p(name.encode('utf-8')),ctypes.cast(ctypes.pointer(data),ctypes.c_void_p))# call library
```
>*Note* `callDiderot_observ()` is the name of the function in *observ_init.c* we want to call. 

### 4. Running the whole thing (run.sh)
* Change path to Diderot-Dev compiler in  data/makedefs.gmk and in the relevant diderot program
* Install  [Firedrake](https://www.firedrakeproject.org/download.html "Firedrake") and activate with 
	 > source firedrake/bin/activate
* Make and run
	> make observ_init.so
	> python observ.py

## Details

* Branch: [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: “see summary above"
* Text: none

## Directory Organization

* Gradient of a field (2-d, Scalar, Unit Square Mesh, element P)  : X1
* ^ (3-d, Scalar, Unit Cube Mesh, Lagrange): X2
* Inner product between vector field and second order tensor field (3-d): X3
