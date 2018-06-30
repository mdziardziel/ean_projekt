import matplotlib.pyplot as plt
import numpy as np
import sys
from math import pow, sin, cos

a = sys.argv[1]
b = sys.argv[2]
x0 = sys.argv[3]
funkcja = sys.argv[4]

x0,lp,pp = x0.split("_")

a = a.replace(',','.')
b = b.replace(',','.')
x0 = x0.replace(',','.')
lp = lp.replace(',','.')
pp = pp.replace(',','.')

a = float(a)
b = float(b)
x0 = float(x0)
funkcja = int(funkcja)
lp = float(lp)
pp = float(pp)

if(lp>pp-0.05):
    pom = lp
    lp = pp
    pp = pom

def generuj_x():
    tmp = []
    lp_tmp = (lp -1)
    while(lp_tmp<= (pp + 1)):
        tmp.append(lp_tmp)
        lp_tmp = lp_tmp+0.05
    return tmp


def funkcja1(x):
    return b*pow(x,2)+a*x-7

def funkcja2(x):
    return a+b*sin(x)

def funkcja3(x):
    print(b)
    return a*pow(0.9,x)*sin(x)-b


def funkcja_oblicz(zakres,nr_fun):
    tmp = []
    for x in zakres:
        if nr_fun == 1:
            tmp.append(funkcja1(x))
        elif nr_fun == 2:
            tmp.append(funkcja2(x))
        elif nr_fun == 3:
            tmp.append(funkcja3(x))
    return tmp




x_w = generuj_x()
y_w = funkcja_oblicz(x_w,funkcja)
plt.plot(x_w, y_w, 'b--', x0, 0, 'ro')
plt.grid(True)
plt.xlim(0, np.pi * 2)
plt.xlabel("x")
#plt.ylabel("f(x) = sin(x)")
plt.title("Wykres funkcji")
#plt.savefig("fig1.jpg", dpi = 72)
plt.show()
