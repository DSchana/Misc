class Node:
	x = -1, y = -1, dist = -1
	def __init__(self, x, y, dist):
		self.dist = dist
		self.x = x
		self.y = y

	def getDist(self):
		return self.dist

	def getX(self):
		return self.x

	def getY(self):
		return self.y

def minMoves(maze, x, y):
	Q = []

	for i in range(len(maze)):
		for j in range(len(maze[i])):
			Q.append(Node(i, j, 10000))

	Q[0].dist = 0

	while len(Q) > 0:
		
