# build.py

import subprocess
import ctypes
import pathlib
import os
import pandas as pd
import plotly.express as px
import plotly.figure_factory as ff
import random

#%% 
if __name__ == '__main__':

    # CALL OPTIMIZER
    assert(os.getcwd() == '/home/roderich/Documents/BAP/gitdir02/dwdforflowshops')
    os.chdir("./build")
    # build from source
    command = "make"
    subprocess.run(command, shell = True)
    # execute
    command = "./binpacking"
    subprocess.run(command, shell = True)
    # remove
    command = "rm binpacking"
    subprocess.run(command, shell = True)

    # LOAD raw gantt data after opt
    df = pd.read_csv('GanttRawData.csv')

    # PREPROCESS raw gantt data for time format
    ref_date = pd.DataFrame({'Date': ['2023-01-01-00-00-00']})
    ref_date = pd.to_datetime(ref_date.Date, format='%Y-%m-%d-%H-%M-%S')

    df['Start'] = df['Start'].apply(lambda x: ref_date[0] + pd.Timedelta(hours=x))
    df['Finish'] = df['Finish'].apply(lambda x: ref_date[0] + pd.Timedelta(hours=x))

    df["Task"] = "Machine: " + df["Machine"].astype(str) + "   Job: " + df["Job"].astype(str)

    


    # PLOT gantt chart 

    # create colormap
    colors={}
    random.seed(100)
    
    for i in range(max(df['Job'])+1):
        colors[i] = 'rgb(%s,%s,%s)'%(random.randint(0,255),random.randint(0,255),random.randint(0,255))

        
    fig = ff.create_gantt(df, colors=colors, index_col='Job')

    fig.show()

