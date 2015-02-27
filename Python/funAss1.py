from pygame import *
from functools import *
from random import *
from math import *

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

def grid(x,y,size,lim):
    if size<=lim:
        draw.rect(screen, (255,255,255), (x,y,size,size),1)
    else:
        grid(x, y, size//2, lim)
        grid(x, y+size//2, size//2, lim)
        grid(x+size//2, y, size//2, lim)
        grid(x+size//2, y+size//2, size//2, lim)
    display.flip()

# fix
def lightning(x,y,size):
    ang = randint(20,150)
    x2 = x + cos(radians(ang)) * size
    y2 = y + sin(radians(ang)) * size
    draw.line(screen, (255, 255, 0), (x, y), (x2, y2), 3)
    if y2 < screen.get_height():
        if y2 <= screen.get_height()/2:
            rate = randint(1,9)
            if rate % 3 == 0:
                rep = 3
            elif rate % 2 == 0:
                rep = 2
            else:
                rep = 1
        else:
            rep = randint(0,3)
        if rep == 0 or rep == 1 or rep == 3:
            for i in range(rep):
                lightning(x2, y2, size)

def star(x,y,size,col):
    points = []
    points.append((x-(108*size)/4*sin(radians(18)), y-size/4))
    points.append((x,y-size))
    points.append((x+(108*size)/4*sin(radians(18)), y-size/4))
    for i in range(len(points)-1):
        draw.line(screen, col, points[i], points[i+1],3)

def clock(hr, m, sec):
    draw.circle(screen, (255, 255, 255), (512, 300), 100)

screen = display.set_mode((1024,600))
screen.fill((0,0,0))
    
running = True
while running:
    for e in event.get():
        if e.type == QUIT:
            running = False

    star(512, 300, 30, (255, 0, 0))
    
    display.flip()

quit()
