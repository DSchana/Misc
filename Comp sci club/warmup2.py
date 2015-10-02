# warmup2.py
#cookies are coolios
def fillX(i, j):
	if tomb[i][j] == ".":
		tomb[i][j] = "X"
		if i != r-1:
			fillX(i+1, j)
		if i != 0:
			fillX(i-1, j)
		if j != 0:
			fillX(i, j-1)
		if j != c-1:
			fillX(i, j+1)

userIn = input()
r = int(userIn[:userIn.index(" ")])
c = int(userIn[userIn.index(" ")+1:])
t = 0

tomb = []

for i in range(r):
	tomb.append([])
	value = input()
	for j in range(c):
		tomb[i].append(value[j])

for i in range(r):
	for j in range(c):
		if tomb[i][j] == ".":
			fillX(i, j)
			t += 1

print(t)
