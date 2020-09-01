import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv("text/results.txt", sep="\n", header=None)
data.rename(columns={0 : 'ratio'}, inplace=True)
data.plot()
plt.ylim(0.5, 3)
plt.yticks(np.arange(0.5, 3, 0.2))
plt.xlabel('time (seconds)')
plt.ylabel('ratio (new / old)')
plt.show()
