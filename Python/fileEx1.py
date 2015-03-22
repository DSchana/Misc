names = open("File Exercise Data/Names.txt", "r").read().strip().split("\n").sort()

for name in names:
	print(name.split(" ")[0])