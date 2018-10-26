def dec(s):
	t = 0
	for i in range(len(s) - 1):
		if (int(s[i:i + 2]) <= 26):
			t += 1

	return t

inp = input()

tot = 1

for i in range(len(inp) - 2):
	tot += dec(inp[i:i + 3])

print(tot)
