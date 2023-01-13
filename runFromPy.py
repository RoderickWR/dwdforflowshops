# build.py

import subprocess
import ctypes
import pathlib
import os
import pandas as pd
import plotly.express as px
import plotly.figure_factory as ff

#%% 
if __name__ == '__main__':

    assert(os.getcwd() == '/home/roderich/Documents/BAP/gitdir02/dwdforflowshops')
    os.chdir("./build")

    command = "./binpacking"
    subprocess.run(command, shell = True)
    # LOAD raw gantt data after opt
    df = pd.read_csv('GanttRawData.csv')
    # PREPROCESS raw gantt data for time format
    ref_date = pd.DataFrame({'Date': ['2023-01-01-00-00-00']})
    ref_date = pd.to_datetime(ref_date.Date, format='%Y-%m-%d-%H-%M-%S')

    df['Start'] = df['Start'].apply(lambda x: ref_date[0] + pd.Timedelta(hours=x))
    df['Finish'] = df['Finish'].apply(lambda x: ref_date[0] + pd.Timedelta(hours=x))

    df["Task"] = "Machine: " + df["Machine"].astype(str) + "   Job: " + df["Job"].astype(str)

    fig = ff.create_gantt(df)


    # fig = px.bar(df, x="Start", y="Job", title= "test")
    fig.show()

