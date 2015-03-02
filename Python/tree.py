# tree.py

from pygame import *
from math import *
from random import *

def tree(screen, x, y, size, ang):
	x2 = x + cos(radians(ang)) * size
	y2 = y - sin(radians(ang)) * size
	draw.line(screen, (255, 255, 255), (x, y), (x2, y2))
	display.flip()
	if size > 5:
		tree(screen, x2, y2, size - randint(7,13), ang - randint(25, 35))
		tree(screen, x2, y2, size - randint(7,13), ang + randint(-5, 5))
		tree(screen, x2, y2, size - randint(7,13), ang + randint(25, 35))

screen = display.set_mode((800, 600))

#screen.fill((0,0,0))
#tree(screen, 400, 600, 80, 90)

for i in range(9):
	for j in range(7):
		tree(screen, i*100, j*100, 50, 90)

running = True

while running:
	for e in event.get():
		if e.type == QUIT:
			running = False
		if e.type == MOUSEBUTTONDOWN:
			#screen.fill((0,0,0))
			tree(screen, mx, my, 50, 90)

	mx,my = mouse.get_pos()

	display.flip()

quit()
