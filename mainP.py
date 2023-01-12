# build.py
from distutils.ccompiler import new_compiler
import subprocess
import ctypes
import pathlib

#%% 
if __name__ == '__main__':
    # compiler = new_compiler()
    # compiler.compile(['mainC.c'])
    # compiler.link_executable(['mainC.o'], 'main')
    # subprocess.call()
    command = "gcc -c mainC.c "
    subprocess.run(command, shell = True)


    #%% 
    # cmd = ["gcc", "mainC.o", "-shared", "-o" , "libmainC.so"]
    command = "gcc mainC.o -shared -o libmainC.so"
    subprocess.run(command, shell = True)
    #%% 

    # Load the shared library into ctypes
    libname = pathlib.Path().absolute() / "libmainC.so"
    c_lib = ctypes.CDLL(libname)
    c_lib.main()
