tot = 4.0

def calc_pi():
	global tot

	if count == 0:
		yield 4.0
	else:
		for i in range(count, -1, -1):
			tot += (-1 ** i) / (2 * i + 1)
			yield tot

count = int(input())
gen = calc_pi()

for i in range(count):
	next(gen)

print(str(round(next(gen), 4)))
