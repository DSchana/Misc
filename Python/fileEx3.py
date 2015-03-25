stocks = {}
for line in open("File Exercise Data/stocks.txt", "r").read().strip().split("\n"):
	name, code, val = line.split("\t")[:3]
	stocks[code] = (name, float(val))
total = 0
for line in open("File Exercise Data/stockProfile.txt", "r").read().strip().split("\n"):
	code, num = line.split("\t")
	name, val = stocks[code]
	value = val*float(num)
	total += value
	print("%-40s $%8.2f" % (name, value))
print("Total: $%.2f" % total)