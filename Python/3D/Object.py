# Object.py
from pygame import *
from math import *

class Object:
	def __init__(self, x, y, size, distance):
		self.x = x
		self.y = y
		self.size = size
		self.distance = distance

	def getPoints(self):
		points1 = []
		points2 = []
		points1.append((self.x, self.y))
		points1.append((self.x+(self.size+self.distance), self.y))
		points1.append((self.x+(self.size+self.distance), self.y+(self.size+self.distance)))
		points1.append((self.x, self.y+(self.size+self.distance)))

		points2.append((self.x + ((self.size)//2), self.y + ((self.size)//2)))
		points2.append(((self.x + (self.size)//2)+self.distance*1.3, self.y + ((self.size)//2)))
		points2.append(((self.x + (self.size)//2)+self.distance*1.3, (self.y + (self.size)//2)+self.distance*1.3))
		points2.append((self.x + ((self.size)//2), (self.y + (self.size)//2)+self.distance*1.3))

		return points1, points2

	def moveObject(self, direction):
		if direction == "forward":
			self.distance += 1
		if direction == "backward":
			self.distance -= 1
		if direction == "right":
			self.x -= abs(self.distance//50)
		if direction == "left":
			self.x += abs(self.distance//50)

		if self.distance+self.size <= 1:
			self.distance += 1

	def displayObject(self, screen):
		points1, points2 = self.getPoints()

		draw.lines(screen, (255, 255, 255), True, points1, 2)
		draw.lines(screen, (255, 255, 255), True, points2, 2)
		for i in range(len(points1)):
			draw.line(screen, (255, 255, 255), points1[i], points2[i], 2)