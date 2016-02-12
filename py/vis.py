import matplotlib.pyplot as plt
from matplotlib import colors
import six, sys
from matplotlib.patches import Polygon
from matplotlib.collections import PatchCollection
import random
import matplotlib

try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()



def Vis(tilebis,stuff):

    if tilebis.dim(isl.dim_type.param) > 0:
        sys.exit()

    #colors_ = list(six.iteritems(colors.cnames))
    colors_ = ['r', 'b','g','c','y']

    fig, ax = plt.subplots()

    patches = []

    tilex = -1
    tiley = -1
    tilept = []

    while(not tilebis.is_empty()):
        s = tilebis.lexmin()
        tilebis = tilebis.subtract(s)
        point =  s.sample_point()
        point = str(point)
        point = point.replace('[', '')
        point = point.replace(']', '')
        point = point.replace(' ', '')
        point = point.split(',')
        point = [int(i) for i in point]

        ax.plot([point[2]], [point[3]], 'bo')

        if((point[0] != tilex ) or (point[1] != tiley)):
            if(len(tilept) > 0):
                tilept = convex_hull(tilept)
                polygon = Polygon(tilept, True, facecolor='red')
                patches.append(polygon)
                tilept = []

            tilept.append((point[2],point[3]))
            tilex = point[0]
            tiley = point[1]
        else:
            tilept.append((point[2],point[3]))

    #draw the last
    if(len(tilept) > 0):
        polygon = Polygon(convex_hull(tilept), True)
        patches.append(polygon)


    p = PatchCollection(patches, cmap=matplotlib.cm.jet, alpha=0.4)


    ax.add_collection(p)

    if '-' in stuff[0]['ub'] or '-' in stuff[1]['ub']:
        print 'Error. Change upper bounds with <= to < in the source loops.'
        sys.exit(0);

    ax.axis([int(stuff[0]['lb'])-1, int(stuff[0]['ub'])+1, int(stuff[1]['lb'])-1, int(stuff[1]['ub'])+1])

    plt.show()



TURN_LEFT, TURN_RIGHT, TURN_NONE = (1, -1, 0)
def turn(p, q, r):
    """Returns -1, 0, 1 if p,q,r forms a right, straight, or left turn."""
    return cmp((q[0] - p[0])*(r[1] - p[1]) - (r[0] - p[0])*(q[1] - p[1]), 0)
def _dist(p, q):
    """Returns the squared Euclidean distance between p and q."""
    dx, dy = q[0] - p[0], q[1] - p[1]
    return dx * dx + dy * dy
def _next_hull_pt(points, p):
    """Returns the next point on the convex hull in CCW from p."""
    q = p
    for r in points:
        t = turn(p, q, r)
        if t == TURN_RIGHT or t == TURN_NONE and _dist(p, r) > _dist(p, q):
            q = r
    return q

def convex_hull(points):
    """Returns the points on the convex hull of points in CCW order."""
    hull = [min(points)]
    for p in hull:
        q = _next_hull_pt(points, p)
        if q != hull[0]:
            hull.append(q)
    return hull