# bronze 5.py

tree = input()
mark = []
high = []
worth = []

for i in range(4):
    userIn = input()
    mark.append(int(userIn[:userIn.index(" ")]))
    del userIn[:userIn.index(" ")+1]
    high.append(int(userIn[:userIn.index(" ")]))
    worth.append(int(userIn[userIn.index(" ")+1:]))

loc = worth.index(max(worth))
if tree == "trees!":
    mark[loc] = high[loc]

tot = sum(mark)
