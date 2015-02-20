from pygame import *

def etri(screen, col, x, y, size):
	h = size*0.866
	draw.line(screen, col, (x, y), (x+size, y))
	draw.line(screen, col, (x, y), (x+size//2, y-int(h)))
	draw.line(screen, col, (x+size//2, y-int(h)), (x+size, y))

def sierp(screen, col, x, y, size):
	etri(screen, col, x, y, size)
	display.flip()
	if size > 3:
		sierp(screen, col, x, y, size / 2)
		sierp(screen, col, x + size/2, y, size / 2)
		sierp(screen, col, x + size/4, y - size*0.433, size / 2)

screen = display.set_mode((800, 600))

sierp(screen, (0, 255, 0), 200, 500, 400)

running = True
while running:
	for e in event.get():
		if e.type == QUIT:
			running = False

	display.flip()

quit()