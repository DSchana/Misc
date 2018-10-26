inp = input().strip("[]").split(",")
inp.sort()

h = 0

for i in range(len(inp)):
	if int(inp[i]) >= i:
		h = i
	else:
		break

print(h)
