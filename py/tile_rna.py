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

#######################################################################
# [S1 | S2]
# TILE_LT_S1
# TILE_GT_S1
# TILE_LT_S2
# TILE_GT_S2

# iloczyny

lex_s1 = ' ( (ii > iip) or (ii = iip && jj > jjp) or (ii=iip && jj=jjp & kk > kkp) ) '
lex_s2 = ' ( (ii > iip) or (ii = iip && jj > jjp) ) '
lex_s1s2 = ' ( (ii > iip) or (ii = iip && jj > jjp) or (ii=iip && jj=jjp)  ) '

lex_s1_g = ' ( (ii < iip) or (ii = iip && jj < jjp) or (ii=iip && jj=jjp & kk < kkp) ) '
lex_s2_g = ' ( (ii < iip) or (ii = iip && jj < jjp) ) '
lex_s1s2_g = ' ( (ii < iip) or (ii = iip && jj < jjp) or (ii=iip && jj=jjp)  ) '

iig0 = ' ii >= 0 && jj >= 0 && kk>= 0 && iip >= 0 && jjp >= 0 && kkp>= 0 && '

bilb1 = ' N-1 - b1*ii >= 0 && '
bilb1p = ' N-1 - b1*iip >= 0 && '

bilb2 = '(i+1) + b2 * jj <= N-1 && '
bilb2p = '(i+1) + b2 * jjp <= N-1 && '

bilb3 = 'b3*kk + 0 <= j-i-1 && '
bilb3p = 'b3*kkp + 0 <= j-i-1 && '

tile_ip_s1 = tile_i_s1.replace('ii', 'iip')
tile_jp_s1 = tile_j_s1.replace('jj', 'jjp')
tile_kp_s1 = tile_k_s1.replace('kk', 'kkp')

template = '[N,ii,jj,kk] -> {[i,j,k,1] : exists iip,jjp,kkp : ('

#######################################################################

TILE_LT_S1_S1 = template
TILE_LT_S1_S1 += lex_s1 + ' && ' + iig0
TILE_LT_S1_S1 += bilb1 + bilb1p + bilb2 + bilb2p + bilb3 + bilb3p

IinTILE = tile_ip_s1 + tile_jp_s1 + tile_kp_s1

TILE_LT_S1_S1 += IinTILE + ')}'

TILE_LT_S1_S1 = TILE_LT_S1_S1.replace('b1', b1)
TILE_LT_S1_S1 = TILE_LT_S1_S1.replace('b2', b2)
TILE_LT_S1_S1 = TILE_LT_S1_S1.replace('b3', b3)

TILE_LT_S1_S1 = isl.Set(TILE_LT_S1_S1)

print '---'

print TILE_LT_S1_S1

#######################################################################

TILE_LT_S1_S2 = template
TILE_LT_S1_S2 += lex_s2 + ' && ' + iig0
TILE_LT_S1_S2 += bilb1 + bilb1p + bilb2 + bilb2p + bilb3

IinTILE = tile_ip_s1 + tile_jp_s1
TILE_LT_S1_S2 += IinTILE + ' 1=1  )}'  #s2

TILE_LT_S1_S2 = TILE_LT_S1_S2.replace('b1', b1)
TILE_LT_S1_S2 = TILE_LT_S1_S2.replace('b2', b2)
TILE_LT_S1_S2 = TILE_LT_S1_S2.replace('b3', b3)

print TILE_LT_S1_S2

TILE_LT_S1_S2 = isl.Set(TILE_LT_S1_S2)

print '---'

print TILE_LT_S1_S2

#######################################################################