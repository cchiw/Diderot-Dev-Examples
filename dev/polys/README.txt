
This directory holds examples of defining different fields with Diderot.
In each example, the first line produces a tensor (expected result) and the second line tests the corresponding ofield definition.

A description of the examples in each diderot program.

del_1.diderot and del_2.diderot
Simple field definitions. We take up to three levels of differentiation of them 

Sphere.diderot
phi(real r) = (1 - r)^4; and phi(real r)
enr(vec2 x) = phi(|x|/rad);

Circle.diderot
function real  phi(real r) = 1/tan(r*π/2) + r*π/2 - π/2;
function real  phi(real r) =  (1/r)*(1 - r)^3;

multiple.diderot
experiments with using multiple input variables