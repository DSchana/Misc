toSort = [5, 6, 3, 1, 2, 4, 9]
k = max(toSort)
count = [0] * (k + 1)
output = [0] * (k + 1)

for x in toSort:
	count[x] += 1

total = 0
for i in range(k + 1):
	oldCount = count[i]
	count[i] = total
	total += oldCount

for x in toSort:
	output[count[x]] = x
	count[x] += 1

print(output)
