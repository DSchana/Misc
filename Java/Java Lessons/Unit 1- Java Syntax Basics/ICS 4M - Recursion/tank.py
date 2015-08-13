# tank.py

def path(tot, loc, pth):
    global fastest, bestPath
    x,y = loc
    if loc == (7,7):
        if tot < fastest:
            fastest = tot
            bestPath = pth
    else:
        if x<7:
            path(tot+grid[x][y],(x+1,y), pth +"D")
        if y<7:
            path(tot+grid[x][y],(x,y+1), pth +"R")

inFile = open("terrain.txt", "r")
grid = []
fastest = 10000
bestPath = ""

for i in range(8):
    text = inFile.readline()
    grid.append(map(int, text.split(" ")))


inFile.close()

path(0, (0,0), "")
print fastest
print bestPath
