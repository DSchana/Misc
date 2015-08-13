# main.py

from pygame import *
from random import *
from Object import *
from Cube import *
import os

os.environ['SDL_VIDEO_WINDOW_POS'] = '100,50'
screen = display.set_mode((1000, 900))

display.set_caption("3D")

clock = time.Clock()
cube = Cube(500, 50, 2000, 50)

running = True
while running:
	screen.fill((0, 0, 0))
	for e in event.get():
		if e.type == QUIT:
			running = False

	pressed = key.get_pressed()

	cube.updateVar(pressed)
	cube.render(screen)

	display.flip()

quit()
