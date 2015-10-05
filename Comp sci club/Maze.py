# Maze.py

def count(x, y, tot, maze):
	if x==c and y==r:
		return tot
	elif maze[x][y] == "+":
		if x-1 < 0 and maze[x-1][y]=="*":
			return tot + count(x-1, y, tot+1)
		if x+1 > c and maze[x+1][y]=="*":
			return tot + count(x+1, y, tot+1)
		if y-1 < 0 and maze[x][y-1]=="*":
			return tot + count(x, y-1, tot+1)
		if y+1 > r and maze[x][y+1]=="*":
			return tot + count(x, y+1, tot+1)
	
	elif maze[x][y] == "-":
		if x-1 < 0 and maze[x-1][y]=="*":
			return tot + count(x-1, y, tot+1)
		if x+1 > c and maze[x+1][y]=="*":
			return tot + count(x+1, y, tot+1)

	elif maze[x][y] == "|":
		if y-1 < 0 and maze[x][y-1]=="*":
			return tot + count(x, y-1, tot+1)
		if y+1 > r and maze[x][y+1]=="*":
			return tot + count(x, y+1, tot+1)

t = int(input())

cases = []

for i in range(t):
	r = int(input())
	c = int(input())
	mazeIn = []
	for j in range(c):
		mazeIn.append(input())

	cases.append(r)
	cases.append(c)
	cases.append(mazeIn)

for i in range(0, len(cases), 3):
	print(count(cases[i+1], cases[i], 0, cases[i+2]))