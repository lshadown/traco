#Python 3
# http://linpy.readthedocs.org/en/latest/tutorial.html

from linpy import *
import matplotlib.pyplot as plt
from matplotlib import pylab
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.patches import FancyArrowPatch
from mpl_toolkits.mplot3d import proj3d
import numpy as np
from numpy import *

class Arrow3D(FancyArrowPatch):
    def __init__(self, xs, ys, zs, *args, **kwargs):
        FancyArrowPatch.__init__(self, (0,0), (0,0), *args, **kwargs)
        self._verts3d = xs, ys, zs

    def draw(self, renderer):
        xs3d, ys3d, zs3d = self._verts3d
        xs, ys, zs = proj3d.proj_transform(xs3d, ys3d, zs3d, renderer.M)
        self.set_positions((xs[0],ys[0]),(xs[1],ys[1]))
        FancyArrowPatch.draw(self, renderer)


x, y, z = symbols('x y z')
fig = plt.figure()

plot = fig.add_subplot(1, 1, 1, projection='3d', aspect='equal')
plot.set_title('Chamfered cube')




poly = Polyhedron('1 <= x <= 3, 1 <= y <= 3, 1 <= z <= 3')
poly2 = Polyhedron('4 <= x <= 6, 1 <= y <= 3, 1 <= z <= 3')

poly3 = Polyhedron('x==1, 0<=y<=1, 0 <= z <= 1')

plot.plot([0],[0],[0], 'ro')

#poly2 = poly.union(poly2)



a = Arrow3D([0, 0], [0, 1], [0, 1], mutation_scale=20, lw=1, arrowstyle="-|>", color="k", alpha=0.3)
plot.add_artist(a)

d = Domain(poly | poly2)
#d.plot(plot, facecolor='red', alpha=0.3)

poly3.plot(plot, facecolor='blue', alpha=0.3)




pylab.show()