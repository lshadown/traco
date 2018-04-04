import re

linestring = open('schedule.txt', 'r').read()
lines = linestring.split('\n')

#print lines
lev = 0
sch_out = {}

iterators = ['i','j','k']
statements = ['S1', 'S2']

lev_st = {'S1' : 3, 'S2' : 2}


for l in lines:
    if "schedule" in l:
        result = re.findall(r'{[^{]+}', l)
        lev = lev + 1
        #print 'Loop nest ' + str(lev) + '   ### '
        pairs = {}
        for r in result:

            maps = r.split(';')
            for m in maps:

                #print m;
                #detect statement
                res = re.findall(r'S\d', m)
                sd = res[0]
                item = re.findall(r'\([^\(]+\)', m)[0].replace('(', '').replace(')', '')
                #print sd + ' ' + item

                if(pairs.has_key(sd)):
                    pairs[sd] = pairs[sd] + '+' + item
                else:
                    pairs[sd] = item

            #print pairs

        sch_out[str(lev)] = pairs

print sch_out


for s in statements:
    map = '{' + s + '['
    for i in range(0, lev_st[s]):
        map += iterators[i] + ','
    map = map[:-1] + '] -> ['


    for i in range(0, lev_st[s]):
        if sch_out.has_key(str(i+1)):
            map += sch_out[str(i+1)][s] + ','
        else:
            map += iterators[i] + ','

    map = map[:-1] + ']}'
    print map





'''
domain: "[N] -> { S2[i, j] : i <= 0 and -i < j < N; S1[i, j, k] : i <= 0 and j < N and 0 <= k < i + j }"
child:
  schedule: "[N] -> [{ S2[i, j] -> [(i)]; S1[i, j, k] -> [(i)] }, { S2[i, j] -> [(j)]; S1[i, j, k] -> [(j)] }]"
  permutable: 1
  coincident: [ 1, 1 ]
  child:
    schedule: "[N] -> [{ S2[i, j] -> [(j)]; S1[i, j, k] -> [(k)] }]"
    permutable: 1
    coincident: [ 1 ]
'''

'''
{S1[i,j,k] -> [i+j,k,k]}
{S2[i,j] -> [i+j,j]}
'''
