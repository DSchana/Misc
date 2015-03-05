from pygame import *
from functools import *
from random import *
from math import *
from datetime import *

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

def lightning(x,y):
    top = [1,1,1,1,1,1,1,1,1,2,2,2]
    bot = [0,0,1,1,1,1,1,2,2,2,2,2]
    shuffle(top)
    shuffle(bot)
    if y < screen.get_height()/2:
        branch = top[0]
    else:
        branch = bot[0]
    for i in range(branch):
        ang = randint(-40, 40)
        down = randint(30, 50)
        draw.line(screen, (255, 255, 0), (x, y), (x+ang, y+down), 2)
        if y<screen.get_height():
            lightning(x+ang, y+down)

def star(x,y,size,col):
    d1 = int(3*size/4)
    d2 = int(size/4)
    points = []
    points.append((x, y+(size*sin(radians(18))/sin(radians(72)))))
    points.append((x-(size*sin(radians(18))/sin(radians(72))+(d1/sin(radians(72)))*sin(radians(18))), y+(d1/sin(radians(72)))*sin(radians(72))))
    points.append((x-(size*sin(radians(18))/sin(radians(72))), y))
    points.append((x-((d1*sin(radians(18)))+d1)/sin(radians(72)), y-d2))
    points.append((x-(d1*sin(radians(18))/sin(radians(72))), y-d2))
    
    points.append((x, y-size))
    points.append((x+(d1*sin(radians(18))/sin(radians(72))), y-d2))
    points.append((x+((d1*sin(radians(18)))+d1)/sin(radians(72)), y-d2))
    points.append((x+(size*sin(radians(18))/sin(radians(72))), y))
    points.append((x+(size*sin(radians(18))/sin(radians(72))+(d1/sin(radians(72)))*sin(radians(18))), y+(d1/sin(radians(72)))*sin(radians(72))))

    draw.lines(screen, col, True, points, 2)
    draw.circle(screen, col, (x, y), 3)  # temporary

def clock(h, m, s):
    draw.circle(screen, (0, 0, 0), (512, 300), 100)
    draw.circle(screen, (255, 255, 255), (512, 300), 100, 3)

    ls = 85
    lm = 85
    lh = 70

    ang_s = s*6
    ang_m = m*(1/10)
    ang_h = h*(1/40)

    s1 = (512, 300)
    m1 = (512, 300)
    h1 = (512, 300)

    s2 = (512 + (ls*sin(radians(ang_s))), 300 - (ls*cos(radians(ang_s))))
    m2 = (512 + (lm*sin(radians(ang_m))), 300 - (lm*cos(radians(ang_m))))
    h2 = (512 + (lh*sin(radians(ang_h))), 300 - (lh*cos(radians(ang_h))))

    draw.line(screen, (255, 0, 0), s1, s2)
    draw.line(screen, (0, 255, 0), m1, m2)
    draw.line(screen, (0, 0, 255), h1, h2)

screen = display.set_mode((1024,600))
screen.fill((0,0,0))
    
running = True
while running:
    for e in event.get():
        if e.type == QUIT:
            running = False

    # run clock
    current = datetime.now()
    h = current.hour
    m = current.minute
    s = current.second
    clock(h, m, s)
    
    display.flip()
quit()
