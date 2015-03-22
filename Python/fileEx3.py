def find(l, elem):
    for row, i in enumerate(l):
        try:
            column = i.index(elem)
        except ValueError:
            continue
        return row, column
    return -1

stocks = open("File Exercise Data/stocks.txt", "r").read().strip().split("\n")
stockProfile = open("File Exercise Data/stockProfile.txt", "r").read().strip().split("\n")
stockCode = []
numOfStocks = []
tot = 0

print("%-40s | %-10s | %10s" % ("Stock Name", "Stock Code", "Value"))
print("-"*68)
for i in range(len(stocks)):
	stocks[i] = stocks[i].split("\t")
	print("%-40s | %-10s | $ %10s" % (stocks[i][0].strip(), stocks[i][1], stocks[i][2]))

print("\n%-10s | %-15s" % ("Stock Code", "# of stocks"))
print("-"*24)
for stock in stockProfile:
	stock = stock.split("\t")
	stockCode.append(stock[0])
	numOfStocks.append(stock[1])
	print("%-10s | %-15s" % (stock[0], stock[1]))

for i in range(len(numOfStocks)):
	pos = find(stocks, stockCode[i])
	price = float(stocks[pos[0]][pos[1]+1])*float(numOfStocks[i])
	tot += price
	
print("\nPrice:", tot)