import numpy as np
import matplotlib.pyplot as plt
import math

N = 7
ind = np.arange(N)  # the x locations for the groups
width = 0.15      # the width of the bars

xlab = ('1', '2', '4', '6', '8', '10', '12')

plik = 'dane2.txt'

linestring = open(plik, 'r').read()
lines = linestring.split('\n')

chart = 0
#titles = ['FT (N=500)', 'FT (N=500)', 'FT (N=500)', 'FT (N=500)']
leg_lab = ('TRACO16', 'PLUTO16', 'TRACO32', 'PLUTO32')

fig = plt.figure()
fig.patch.set_facecolor('#ffffff')
dane = [[],[],[],[]]

for line in lines:
    if '%%' in line:
        title = line.replace('%% ', '')
        continue
    if line != '' and not '%' in line:

        items = line.split('\t')
        items = (list(map(float, items)))

        for i in range(0,4):
            dane[i].append(items[i])

    if '% ---' in line:
        chart = chart + 1


        if plik == 'dane2.txt' and chart >= 5 and chart <= 6:
            leg_lab = ('TRACO200', 'PLUTO200', 'TRACO400', 'PLUTO400')
        else:
            leg_lab = ('TRACO (block=16)', 'PLUTO (block=16)', 'TRACO (block=32)', 'PLUTO (block=32)')


        ax1 = fig.add_subplot(5,2,chart)

        rects1 = ax1.bar(ind-width, dane[0], width, color='#ff0000')
        rects2 = ax1.bar(ind, dane[1], width, color='#00ff00')
        rects3 = ax1.bar(ind+width, dane[2], width, color='#9900ff')
        rects4 = ax1.bar(ind+2*width, dane[3], width, color='#ffff00')

        low = min(min(dane))
        high = max(max(dane))
        plt.ylim([0, high+1])

        ax1.set_ylabel('Speed-up')
        ax1.set_title(title)
        ax1.set_xticks(ind+width)
        ax1.set_xticklabels( xlab )
        #ax1.set_xlabel('CPUs')
        ax1.annotate('CPUs', xy=(1, 0), xycoords='axes fraction', fontsize=12, xytext=(20, -18), textcoords='offset points', ha='right', va='bottom')

        #ax1.legend((rects1[0], rects2[0], rects3[0], rects4[0]), leg_lab, loc=2, prop={'size':8})
        ax1.margins(0.01, 0)
        dane = [[],[],[],[]]

    if chart == 10:
        break
fig.subplots_adjust(left=0.05, bottom=0.05, right=0.95, top=0.92, wspace=None, hspace=0.3)


plt.legend( (rects1[0], rects2[0], rects3[0], rects4[0]), leg_lab, loc = 'upper center', bbox_to_anchor = (0,-0.01,1,1),
            bbox_transform = plt.gcf().transFigure, ncol=4,  prop={'size':11} )

plt.show()
