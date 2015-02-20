from pygame import *
from functools import *

def numFactors(n):
    tot = 0
    for i in range(1,n+1):
        if n%i == 0:
            tot += 1

    return tot

def subtract(n1,n2):
    new = []
    for i in n1:
        if i not in n2:
            new.append(i)
    return new

def similar(w1,w2):
    tot = 0
    for i in w1:
        if i in w2:
            tot += 1
            w2 = w2.replace(i,"",1)
    return float(tot/len(w1)*100)

@lru_cache()
def grid(x,y):
    if x>=10:
        
screen = display.set_mode((500,500))
screen.fill((0,0,0))
