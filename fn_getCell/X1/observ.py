import sys
from firedrake import *
from os.path import abspath, dirname
import pytest
import os
from os import path
cwd = abspath(dirname(__file__))

sys.path.insert(0, '../../data/')
from init import *


import ctypes
from ctypes import POINTER, c_int, c_double, c_void_p, c_float
import numpy
import numpy.ctypeslib as npct


imgpath = ''

# init diderot program
def observ(name, f, res, stepSize, cell):
    init_file = 'observ_init.so'
    _call = ctypes.CDLL(init_file)
    data = organizeData(f)
    _call.callDiderot_observ.argtypes = (ctypes.c_char_p,ctypes.c_int,ctypes.c_void_p,ctypes.c_int,ctypes.c_float)
    result = _call.callDiderot_observ(ctypes.c_char_p(name), cell,ctypes.cast(ctypes.pointer(data),ctypes.c_void_p), res, stepSize)
    return(result)


# define field
def vis_exp(cell):
    lbl = "x"
    exp = "x[0]" #"x[0]*x[0]*(1-x[0])"
    mesh = UnitSquareMesh(2,2)
    V= FunctionSpace(mesh,"Lagrange",degree=2)
    f = Function(V).interpolate(Expression(exp))
    name = lbl+"_cell_"+str(cell)
    #progrm creates step size
    res = 300
    stepSize = 1.0/res
    datafile = imgpath+name
    namepng = datafile +'.png'
    namenrrd = datafile +'.nrrd'
    observ(namenrrd, f, res, stepSize, cell)
    #visualize result
    quantize(namenrrd, namepng)
    os.system('open ' + namepng)



for i in range(8):
    vis_exp (i)
