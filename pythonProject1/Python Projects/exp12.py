import matplotlib.pyplot as mpy
import numpy as np

x = np.linspace(-10, 10, 10000000)
y = x ** 2
mpy.plot(x, y, color='skyblue')
mpy.show()
