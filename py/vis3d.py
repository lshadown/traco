#Python 3
# http://linpy.readthedocs.org/en/latest/tutorial.html

from linpy import *
import matplotlib.pyplot as plt
from matplotlib import pylab
from mpl_toolkits.mplot3d import Axes3D

x, y, z = symbols('x y z')
fig = plt.figure()
plot = fig.add_subplot(1, 1, 1, projection='3d', aspect='equal')
plot.set_title('Chamfered cube')

poly = Polyhedron('1 <= x <= 3, 1 <= y <= 3, 1 <= z <= 3')

poly.plot(plot, facecolor='red', alpha=0.75)

poly2 = Polyhedron('4 <= x <= 6, 1 <= y <= 3, 1 <= z <= 3')

poly2.plot(plot, facecolor='blue', alpha=0.75)

pylab.show()
