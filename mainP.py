# build.py
from distutils.ccompiler import new_compiler
import subprocess

if __name__ == '__main__':
    compiler = new_compiler()
    compiler.compile(['mainC.c'])
    compiler.link_executable(['mainC.o'], 'main')
    subprocess.call()



# ctypes_test.py
import ctypes
import pathlib

if __name__ == "__main__":
    # Load the shared library into ctypes
    libname = pathlib.Path().absolute() / "libmainC.so"
    c_lib = ctypes.CDLL(libname)
    c_lib.main()
