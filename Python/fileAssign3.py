from pygame import *

outFile = open("File assignment data/eyePhysics.py", "w")

outFile.write('''
from pygame import *
screen = display.set_mode((1024, 1024))\n
''')

picture = image.load("File assignment data/eyePhysics Thumbnail copy.png")

for x in range(1024):
	for y in range(1024):
		col = picture.get_at((x, y))
		r = col[0]
		g = col[1]
		b = col[2]
		outFile.write("screen.set_at((%d, %d), (%d, %d, %d))\n" % (x, y, r, g, b))

outFile.write("display.flip()")
outFile.close()