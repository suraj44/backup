import plotly.plotly as py
import plotly.graph_objs as go
import plotly.figure_factory as FF

import numpy as np
import pandas as pd

df = pd.read_csv('hi2.csv')


trace1 = go.Scatter(y= df['Quick'], x = df['Input'],  name='Quicksort')
trace2 = go.Scatter(y= df['Median'], x = df['Input'],  name='Divide and Conquer')

layout = go.Layout(title = 'Time Complexity Analysis', plot_bgcolor = 'rgb(230,230,230)', showlegend = True )

fig = go.Figure(data = [trace1,trace2], layout = layout)

py.plot([trace1,trace2], filename = 'final1')