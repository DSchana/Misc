# main.py
from pygame import *
from random import *
from Object import *

screen = display.set_mode((1000, 900))

display.set_caption("3D")
screen.fill((0, 0, 0))

clock = time.Clock()
cube = Object(300, 200, 200, 100)

running = True
while running:
	for e in event.get():
		if e.type == QUIT:
			running = False

	screen.fill((0, 0, 0))

	pressed = key.get_pressed()
	if pressed[K_UP]:
		cube.moveObject("forward")
	if pressed[K_DOWN]:
		cube.moveObject("backward")
	if pressed[K_RIGHT]:
		cube.moveObject("right")
	if pressed[K_LEFT]:
		cube.moveObject("left")

	cube.displayObject(screen)

	display.flip()

quit()