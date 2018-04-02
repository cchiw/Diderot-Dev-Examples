# Math functions: Field Selection
## In Action
Inside a Diderot program there may be many different field definitions and computations on those fields 
``` 
field#k(d)[α] A;   field#k(d)[α] B;   field#k(d)[α] C;    field#k(d)[α] D;...
```
Typically, this meant that the Diderot programmer would comment some lines in and out and recompile when trying different definitions. To make it easier we created a new function "swap()" that alternates between different field definitions based on the *selection_id.*
```
int selection_id;
field#k(d)[] F = swap(selection_id,A,B,C,D);  
```
As a note, the selection_id can also be an input variable.
``` 
input int selection_id;
```
## Details
* Branch:   [Diderot-Dev](https://github.com/cchiw/Diderot-Dev) 
* Syntax: “swap()"
- fty = field#k(d)[α]
- int × fty × fty → fty
- int × fty × fty× .... → fty
- int × fty × fty × fty × fty × fty × fty → fty
* Arguments
-  *Selection id* The first argument  is an integer that serves to select a field. i.e. id=2 chooses the second field argument
- *Field arguments* The function accepts 2-6 field arguments.
* Potential issue:  The value of the *Selection id* is clamped. If the first argument is id=-7 the id is set to 1 instead of throwing an error 
## Directory Organization
* Examples:
- Global Initialization of the *selection id* in a shaded v.r. program (dvr)  : X1
- The *selection id* is set in the update method  : X2

