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
@lru_cache()
def lightning(x,y):
    top = [0,0,0,0,0,0,1,1,1,1,2,2]
    bot = [1,1,1,1,1,1,1,1,1,2,2,2]
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
        display.flip()
        lightning(x+ang, y+down)

def star(x,y,size,col):
    points = []
    points.append((x-(10*size)/2*sin(radians(18)), y-size/2))
    points.append((x,y-size))
    points.append((x+(10*size)/2*sin(radians(18)), y-size/2))
    for i in range(len(points)-1):
        draw.line(screen, col, points[i], points[i+1],3)

def clock(h, m, s):
    draw.circle(screen, (255, 255, 255), (512, 300), 100)

screen = display.set_mode((1024,600))
screen.fill((0,0,0))
    
running = True
while running:
    for e in event.get():
        if e.type == QUIT:
            running = False

    screen.fill((0,0,0))
    lightning(512, 0)
    
    display.flip()
    time.delay(300)
quit()
