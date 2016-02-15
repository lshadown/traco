import matplotlib.pyplot as plt
from matplotlib import colors
import six, sys
from matplotlib.patches import Polygon
from matplotlib.collections import PatchCollection
import random
import matplotlib
from islplot.plotter import *

try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()



def Vis(tilebis,stuff, deps, domain, Ext=False):

    if tilebis.dim(isl.dim_type.param) > 0:
        sys.exit()

    #colors_ = list(six.iteritems(colors.cnames))
    colors_ = ['r', 'b','g','c','y']

    fig, ax = plt.subplots(facecolor="white")

    patches = []

    tilex = -1
    tiley = -1
    tilept = []


    #for dep2 in deps:
    #    plot_map(dep2.relation)

    plot_set_points((domain), marker=".", size=5, color="gray")

    for dep2 in deps:
        dep = dep2.relation
        while(not dep.is_empty()):
            s = dep.sample()
            dep = dep.subtract(s)

            doms = s.domain()
            ranges = s.range()
            doms = doms.sample_point()
            ranges = ranges.sample_point()
            doms = integer_list(doms)
            ranges = integer_list(ranges)


            ax.annotate("",
                    xy=(ranges[0], ranges[1]), xycoords='data',
                    xytext=(doms[0], doms[1]), textcoords='data',
                    arrowprops=dict(arrowstyle="->",
                                    connectionstyle="arc3"),
                    )




    '''while(not tilebis.is_empty()):
        s = tilebis.lexmin()
        tilebis = tilebis.subtract(s)
        point =  s.sample_point()
        point = str(point)
        point = point.replace('[', '')
        point = point.replace(']', '')
        point = point.replace('{', '')
        point = point.replace('}', '')
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


    ax.add_collection(p)'''

    sufix = ''
    if(Ext):
        sufix = ',v'

    reduce_map = isl.Map('{[ii,jj,i,j'+sufix+'] -> [i,j]}')

    while(not tilebis.is_empty()):
        s = tilebis.lexmin()
    #    tilebis = tilebis.subtract(s)
        point =  s.sample_point()
        point = str(point)
        point = point.replace('[', '')
        point = point.replace(']', '')
        point = point.replace('{', '')
        point = point.replace('}', '')
        point = point.replace(' ', '')
        point = point.split(',')
        point = [int(i) for i in point]
        settile = isl.Set("{[ii,jj,i,j"+sufix+"] : ii = " + str(point[0]) + " and jj = " + str(point[1]) + "}").intersect(tilebis).coalesce()
        tile_points = settile.apply(reduce_map)

        plot_set_shapes((tile_points ), color="blue", alpha=0.3, vertex_size=0)
        #print tile_points
        #print settile
        tilebis = tilebis.subtract(settile)






    if '-' in stuff[0]['ub'] or '-' in stuff[1]['ub']:
        print 'Error. Change upper bounds with <= to < in the source loops.'
        sys.exit(0);

    #ax.axis([-1, 10, -1, 10])

    ax.axis([int(stuff[0]['lb'])-1, int(stuff[0]['ub'])+1, int(stuff[1]['lb'])-1, int(stuff[1]['ub'])+1])
    # Get current size
    fig_size = plt.rcParams["figure.figsize"]


    # Set figure width to 12 and height to 9
    fig_size[0] = 11
    fig_size[1] = 11
    plt.rcParams["figure.figsize"] = fig_size



    plt.show()


# --------------------------------------------------------------------------------------------
# The Jarvis algorithm (gift wrapping)

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

# --------------------------------------------------------------------------------------------

def integer_list(point):
    point = str(point)
    point = point.replace('{', '')
    point = point.replace('}', '')
    point = point.replace('[', '')
    point = point.replace(']', '')
    point = point.replace(' ', '')
    point = point.split(',')
    point = [int(i) for i in point]

    return point