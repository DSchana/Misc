# Faces.py

from pygame import *

class Face:
	def __init__(self, x, y, size, distance):
		"setup coords for face"
		self.distance = distance
		self.size = size
		self.apparant_size = self.size/self.distance/4
		self.x = x
		self.y = y
		self.coords = [(int(self.x), int(self.y)), (int(self.x+self.apparant_size), int(self.y)), (int(self.x+self.apparant_size), int(self.y+self.apparant_size)), (int(self.x), int(self.y+self.apparant_size))]

	def updateVar(self, x, y, size, distance):
		"update variables used in this class"
		self.distance = distance
		self.size = size
		## self.apparant_size = self.size/(self.distance/4)
		self.apparant_size = self.distance/self.size
		self.x = x/(self.distance*0.2)
		self.y = y/(self.distance*0.2)
		self.coords = [(int(self.x), int(self.y)), (int(self.x+self.apparant_size), int(self.y)), (int(self.x+self.apparant_size), int(self.y+self.apparant_size)), (int(self.x), int(self.y+self.apparant_size))]

	def render(self, screen):
		"Display face"
		for i in range(len(self.coords)-1):
			draw.line(screen, (255, 255, 255), self.coords[i], self.coords[i+1])

		draw.line(screen, (255, 255, 255), self.coords[len(self.coords)-1], self.coords[0])
