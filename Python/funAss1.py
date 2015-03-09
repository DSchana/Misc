# functions assignment
# Dilpreet Chana

from pygame import *
from functools import *
from random import *
from math import *
from datetime import *

def numFactors(n):
    "Count the number of factors a number has"
    tot = 0  # tot holds the number of factors
    for i in range(1,n+1):
        if n%i == 0:
            tot += 1 

    return tot

def subtract(n1,n2):
    "Return the difference of 2 strings"
    new = []
    for i in n1:
        if i not in n2:  # check if the current position of n1 is in n2
            new.append(i)
    return new

def similar(w1,w2):
    "Returns percent of similarities between 2 strings"
    tot = 0
    for i in w1:
        if i in w2:
            tot += 1
            w2 = w2.replace(i,"",1)
    return float(tot/len(w1)*100)

def grid(x,y,size,lim):
    "Draw a grid"
    # base case checks if the size of grid is smaller than the limit
    if size<=lim:
        draw.rect(screen, (255,255,255), (x,y,size,size),1)
    else:
        grid(x, y, size//2, lim)
        grid(x, y+size//2, size//2, lim)
        grid(x+size//2, y, size//2, lim)
        grid(x+size//2, y+size//2, size//2, lim)
    display.flip()

def lightning(x,y):
    "Draw lightning"
    # top and bot are randomly selected from to
    # determine the number of branches on the lightning
    # top has less chance ofgetting 2 than bot.
    top = [1,1,1,1,1,1,1,1,1,2,2,2]
    bot = [0,0,1,1,1,1,1,2,2,2,2,2]

    # randomize top and bot
    shuffle(top)
    shuffle(bot)
    # top half of screen
    if y < screen.get_height()/2:
        branch = top[0]
    # bottom half of screen
    else:
        branch = bot[0]
    for i in range(branch):
        dif_x = randint(-40, 40)  # random x difference
        dif_y = randint(30, 50)  # random y difference
        draw.line(screen, (255, 255, 0), (x, y), (x+dif_x, y+dif_y), 2)
        if y<screen.get_height():
            lightning(x+ang, y+down)

def point(x, y, size, ang):
    "Find second point of a line based on point 1, size and angle"
    x2 = x+cos(radians(ang-90))*size
    y2 = y+sin(radians(ang-90))*size
    return (x2, y2)
    
def star(x,y,size,col):
    "Draw a 5 pointed star"
    points = []
    points2 = []
    for i in range(0, 360, 72):
        point1 = point(x,y,size,i)
        point2 = point(x,y,size//2.6,180+i)
        points.append(point1)
        points2.append(point2)
    for i in range(5):
        points2.append(points2[i])
        draw.line(screen, col, points[i], points2[i+2], 2)
        draw.line(screen, col, points[i], points2[i+3], 2)

def clock(h, m, s):
    "Draw a working clock"
    # draw clock face
    ##########################################################
    draw.circle(screen, (0, 0, 0), (512, 300), 100)
    draw.circle(screen, (255, 255, 255), (512, 300), 100, 2)
    for i in range(0, 360, 30):
        x1 = 512+90*cos(radians(i))
        y1 = 300+90*sin(radians(i))
        x2 = 512+100*cos(radians(i))
        y2 = 300+100*sin(radians(i))
        draw.line(screen, (255, 255, 255), (x1, y1), (x2, y2), 1)
    for i in range(0, 360, 6):
        x1 = 512+95*cos(radians(i))
        y1 = 300+95*sin(radians(i))
        x2 = 512+100*cos(radians(i))
        y2 = 300+100*sin(radians(i))
        draw.line(screen, (255, 255, 255), (x1, y1), (x2, y2), 1)
    ###########################################################

    # second hand
    draw.line(screen, (255, 0, 0), (512, 300), point(512, 300, 80, s*6), 2)
    # minute hand
    draw.line(screen, (0, 255, 0), (512, 300), point(512, 300, 80, m*6+s//10), 2)
    # hour hand
    draw.line(screen, (0, 0, 255), (512, 300), point(512, 300, 65, 180+(h*6+m//2)), 2)
 
screen = display.set_mode((1024,600))
screen.fill((0,0,0))
    
running = True
while running:
    for e in event.get():
        if e.type == QUIT:
            running = False

    screen.fill((0, 0, 0))

    # run grid
    grid(0, 0, 300, 10)
            
    # run lightning
    draw.line(screen, (255, 255, 0), (screen.get_width()/2, 0), (screen.get_width()/2, 50), 2)
    lightning(screen.get_width()/2, 50)

    # run star
    star(512, 300, 300, (255, 0, 0))
    
    # run clock
    current = datetime.now()
    h = current.hour
    m = current.minute
    s = current.second
    clock(h, m, s)
    
    display.flip()
quit()
