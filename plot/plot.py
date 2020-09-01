import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import math

data = pd.read_csv("text/results.txt", sep="\n", header=None)
data.rename(columns={0 : 'ratio'}, inplace=True)
for i in data.index:
	if (data.loc[i].ratio == 0):
		data.loc[i].ratio = data.ratio.max()
data.plot()
plt.ylim(0.5, data.ratio.max() / 2.5)
plt.yticks(np.arange(0.5, data.ratio.max() / 2.5, 0.2))
plt.xlabel('time (seconds)')
plt.ylabel('ratio (new / old)')
plt.show()
