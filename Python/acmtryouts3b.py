t = int(input())
texts = []

for i in range(t):
	texts.append(input())

for i in range(t):
	hearts = texts[i].count("<3")
	print("<3 "*(hearts+1))