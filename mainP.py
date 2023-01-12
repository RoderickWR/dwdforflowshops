# build.py

import subprocess
import ctypes
import pathlib

#%% 
if __name__ == '__main__':

    command = "gcc -c mainC.c "
    subprocess.run(command, shell = True)

    command = "gcc -c mainC2.c "
    subprocess.run(command, shell = True)


    #%% 

    command = "gcc mainC.o mainC2.o -shared -o libmainC.so"
    subprocess.run(command, shell = True)
    #%% 

    # Load the shared library into ctypes
    libname = pathlib.Path().absolute() / "libmainC.so"
    c_lib = ctypes.CDLL(libname)
    c_lib.main()
    c_lib.main2()
