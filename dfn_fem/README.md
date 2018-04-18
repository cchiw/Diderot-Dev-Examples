# Field Definition: FEM
We support computations on fields defined by outside sources.
##  In Action
There are four steps to the implementation process: 
 1. Diderot code (observ.diderot) 
 2. C code that communicates to the generated Diderot code   (observ_init.c) 
 3. Python code that initiates the C code and creates FEM data (observ.py)
 4. Running the program (run.sh)

For the most part steps 2-4 are the same for each example and code can be easily reused. 

### 1.Diderot Code (observ.diderot)
The user declares a FEM field with the function``FEM`` and two arguments. The first argument is an input variable and the second is a path to the relevant data file.
```
input fem#k(d)[α] F0;
field#k(d)[α] F = FEM(F0, "data.json");
```
Define a fem field- ``FEM()``: *fem#k(d)[α]* × string    →field#k(d)[α] 


### 2. C code that communicates to the generated Diderot code (observ_init.c)
The C code is used to communicate with the generated Diderot code. The function ```callDiderot_observ()``` can be called by outside tools.
```
void callDiderot_observ(char *Outfile, void *valF)
```
The function takes the name of the output nrrd file and a pointer to the field data.

Otherwise, the code here is FEM independent and does not need augmentation.

### 3. Python code that initiates the C Code (observ.py)
The python code is used to create the fem field data. Otherwise, the  code can be used verbatim. 

It is necessary to have files *init.py **makejson.py* included in the path. Currently saved to the latte/data.
```
sys.path.insert(0, '../../data/') #path to init.py, makejson.py
from init import *
from makejson import *
from firedrake import *
```
A function space is defined and sent to a call function to create a data file.
```
V= FunctionSpace(UnitSquareMesh(4,4),"P",degree=4)
makejson(V,"data.json")
```
The ``makejson()`` call with create the data.json file referred to in the Diderot program. The Diderot program can now be compiled with
```
os.system ("make observ_init.so")	
```
The field is defined by an outside source, such as Firedrake.The field could be the solution to a pde equation or the result of interpolating an expression over a function space. After defining the field ``f0`` the following code is used to pass the field to Diderot. 
```
f0 = Function(V).interpolate(Expression(expf0))
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
	> python observ.py

## Details

* Branch: [Diderot-Dev](https://github.com/cchiw/Diderot-Dev)
* Syntax: “see summary above"
* Text: none

## Directory Organization

* Gradient of a field (2-d, Scalar, Unit Square Mesh, element P)  : X1
* ^ (3-d, Scalar, Unit Cube Mesh, Lagrange): X2
* Inner product between vector field and second order tensor field (3-d): X3
