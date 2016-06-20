import sys

try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()


TILE_S1 = '[N,ii,jj,kk] -> '
TILE_S1 += '{[i,j,k,1] : '

tile_i_s1 = ' N-1 - b1 * ii >= i >= N-1-b1*(ii+1)+1, 0 && ii >=0 && '
tile_j_s1 = ' (i+1) + b2*jj <= j <= b2*(jj+1)+i+1-1, N-1 && jj >= 0 &&'
tile_k_s1 = ' b3*kk + 0 <= k <= b3*(kk+1)+0-1, j-i-1 && kk >= 0  '

TILE_S1 += tile_i_s1 + tile_j_s1 + tile_k_s1 + '}'

#######################################################################

TILE_S2 = '[N,ii,jj,kk] -> '
TILE_S2 += '{[i,j,k,2] : '

tile_k_s2 = ' k=0 && kk=0 '

TILE_S2 += tile_i_s1 + tile_j_s1 + tile_k_s2 + '}'


#######################################################################

b1 = '32'
b2 = '32'
b3 = '32'

TILE_S1 = TILE_S1.replace('b1', b1)
TILE_S1 = TILE_S1.replace('b2', b2)
TILE_S1 = TILE_S1.replace('b3', b3)

TILE_S2 = TILE_S2.replace('b1', b1)
TILE_S2 = TILE_S2.replace('b2', b2)


#######################################################################

TILE_S1 = isl.Set(TILE_S1)
TILE_S2 = isl.Set(TILE_S2)

print TILE_S1

print '---'

print TILE_S2