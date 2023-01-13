# build.py

import subprocess
import ctypes
import pathlib
import os
import pandas as pd

#%% 
if __name__ == '__main__':

    assert(os.getcwd() == '/home/roderich/Documents/BAP/gitdir02/dwdforflowshops')
    os.chdir("./build")

    command = "./binpacking"
    subprocess.run(command, shell = True)

    df = pd.read_csv('GanttRawData.csv')


