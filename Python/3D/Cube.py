# Cube.py

from pygame import *
from Faces import *

class Cube:
	def __init__(self, x, y, size, distance):
		self.x = x
		self.y = y
		self.size = size
		self.distance = distance
		self.face = ["", ""]
		self.face[0] = Face(self.x, self.y, self.size, self.distance)
		self.face[1] = Face(self.x+self.size/(self.distance*10), self.y+self.size/(self.distance*10), self.size, self.distance+self.size/500)

	def updateVar(self, pressed):
		self.move(pressed)
		self.face[0] = Face(self.x, self.y, self.size, self.distance)
		self.face[1] = Face(self.x+self.size/(self.distance*10), self.y+self.size/(self.distance*10), self.size, self.distance+self.size/500)

		print(self.face[0].apparant_size, self.face[1].apparant_size, self.face[0].distance, self.face[1].distance)

	def move(self, pressed):
		"Change position of the cube"
		if pressed[K_EQUALS] and self.distance-1>0:
			self.distance -= 1
		elif pressed[K_MINUS]:
			self.distance += 1

		if pressed[K_UP]:
			self.y += 1
		if pressed[K_DOWN]:
			self.y -= 1
		if pressed[K_RIGHT]:
			self.x -= 1
		if pressed[K_LEFT]:
			self.x += 1

	def render(self, screen):
		"display cube on screen"
		self.face[0].render(screen)
		self.face[1].render(screen)

		for i in range(len(self.face[0].coords)):
			draw.line(screen, (255, 255, 255), self.face[0].coords[i], self.face[1].coords[i])
