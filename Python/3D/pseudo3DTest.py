# pseudo3DTest.py

from pygame import *

def square(start, size):
	node_1 = [start[0], start[1]]
	node_2 = [start[0]+size, start[1]]
	node_3 = [start[0], start[1]+size]
	node_4 = [start[0]+size, start[1]+size]

	offset = int(size/2)
	x_mid = int(800/2)
	x_offset = int(start[0] - x_mid)

	if x_offset > 100:
		x_offset = 100
	elif x_offset < -100:
		x_offset = -100

	node_5 = [node_1[0] + x_offset, node_1[1] - offset]
	node_6 = [node_2[0] + x_offset, node_2[1] - offset]
	node_7 = [node_3[0] + x_offset, node_3[1] - offset]
	node_8 = [node_4[0] + x_offset, node_4[1] - offset]

	# top line
	draw.line(screen, (255, 255, 255), node_1, node_2)
	# bottom line
	draw.line(screen, (255, 255, 255), node_3, node_4)
	# left line
	draw.line(screen, (255, 255, 255), node_1, node_3)
	# right line
	draw.line(screen, (255, 255, 255), node_2, node_4)

	# top line
	draw.line(screen, (255, 255, 255), node_5, node_6)
	# bottom line
	draw.line(screen, (255, 255, 255), node_7, node_8)
	# left line
	draw.line(screen, (255, 255, 255), node_5, node_7)
	# right line
	draw.line(screen, (255, 255, 255), node_6, node_8)

	draw.line(screen, (255, 255, 255), node_1, node_5)
	draw.line(screen, (255, 255, 255), node_2, node_6)
	draw.line(screen, (255, 255, 255), node_3, node_7)
	draw.line(screen, (255, 255, 255), node_4, node_8)

	draw.circle(screen, (0, 255, 0), node_1, 5)
	draw.circle(screen, (0, 255, 0), node_2, 5)
	draw.circle(screen, (0, 255, 0), node_3, 5)
	draw.circle(screen, (0, 255, 0), node_4, 5)
	draw.circle(screen, (0, 255, 0), node_5, 5)
	draw.circle(screen, (0, 255, 0), node_6, 5)
	draw.circle(screen, (0, 255, 0), node_7, 5)
	draw.circle(screen, (0, 255, 0), node_8, 5)

location = [300, 200]
size = 100
z_location = 1

screen = display.set_mode((800, 600))

pseudo_clock = time.Clock()
running = True

while running:
	screen.fill((0, 0, 0))

	pressed = key.get_pressed()
	mx, my = mouse.get_pos()
	mb = mouse.get_pressed()

	for e in event.get():
		if e.type == QUIT:
			running = False

	if pressed[K_RIGHT]:
		location[0] -= 5
	if pressed[K_LEFT]:
		location[0] += 5

	if pressed[K_UP]:
		z_location -= 5
		location[0] -= 1
	if pressed[K_DOWN]:
		z_location += 5
		location[0] += 1

	square(location, int(size/(z_location*0.1)))

	pseudo_clock.tick(60)
	display.flip()
quit()