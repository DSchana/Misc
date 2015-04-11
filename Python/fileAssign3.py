# Dilpreet Chana
# fileAssign3.py
# Program creates a python file to display an image

from pygame import *

outFile = open("File assignment data/image.py", "w")

picture = image.load("File assignment data/dc.png")

outFile.write('''from pygame import *
screen = display.set_mode((%d, %d))\n
''' % (picture.get_width(), picture.get_height()))

for x in range(0, picture.get_width(), 2):
	for y in range(0, picture.get_height(), 2):
		col = picture.get_at((x, y))
		r = col[0]
		g = col[1]
		b = col[2]
		outFile.write("draw.circle(screen, (%d, %d, %d), (%d, %d), 2)\n" % (r, g, b, x, y))
outFile.write('''
display.flip()
done = False
while done == False:
	for e in event.get():
		if e.type == QUIT:
			done = True''')

outFile.close()