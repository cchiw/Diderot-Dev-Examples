import sys
from firedrake import *
from os.path import abspath, dirname
import os
from os import path
cwd = abspath(dirname(__file__))
sys.path.insert(0, '../../data/')

from init import *
from makejson import *

import ctypes
from ctypes import POINTER, c_int, c_double, c_void_p, c_float
import numpy
import numpy.ctypeslib as npct


def compile_Diderot(V):
    #makejson(V,"data.json")# json file already in directory
    os.system("make clean")
    os.system("make observ.o")
    os.system("make observ_init.so")

# single field
def init1(name, f,target):
    init_file = target+'_init.so'
    _call = ctypes.CDLL(init_file)
    type = 1
    data = organizeData(f)
    _call.callDiderot_observ.argtypes = (ctypes.c_char_p,ctypes.c_int,ctypes.c_void_p)
    result = _call.callDiderot_observ(ctypes.c_char_p(name.encode('utf-8')), type,ctypes.cast(ctypes.pointer(data),ctypes.c_void_p))
    return(result)

##############################################
#general declarations
#init field
# call to init




V= FunctionSpace(UnitCubeMesh(4,4,4),"Lagrange",degree=4)
compile_Diderot(V)

expf0 = "0+(-2*1)+(2*x[1])+(-1*x[0])+(-1*x[1]*x[1])+(3*x[1]*x[1]*x[0])+(-1*x[0]*x[0]*x[1]*x[1])+(5*x[0]*x[0]*x[1])+(-3*x[0]*x[0])+(-4*1*x[2])+(5*x[1]*x[2])+(2*x[0]*x[1]*x[2])+(-3*x[0]*x[2])+(-5*x[1]*x[1]*x[2])+(5*x[0]*x[0]*x[1]*x[1]*x[2])+(-5*x[0]*x[0]*x[1]*x[2])+(-2*x[0]*x[0]*x[2])+(-5*1*x[2]*x[2])+(4*x[1]*x[2]*x[2])+(3*x[0]*x[1]*x[2]*x[2])+(-3*x[0]*x[2]*x[2])+(-1*x[1]*x[1]*x[2]*x[2])+(1*x[1]*x[1]*x[0]*x[2]*x[2])+(-5*x[0]*x[0]*x[1]*x[1]*x[2]*x[2])+(3*x[0]*x[0]*x[1]*x[2]*x[2])+(-1*x[0]*x[0]*x[2]*x[2])"
f0 = Function(V).interpolate(Expression(expf0))
name = "output"
target ="observ"
namenrrd = name+'.nrrd'
init1(namenrrd, f0,  target)