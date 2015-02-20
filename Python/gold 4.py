# gold 5.py

userIn = input()
n = userIn[:userIn.index(" ")]
m = userIn[userIn.index(" ")+1:]

userIns = []
A = []
B = []
T = []

for i in range(m):
	userIn = input()
	A.append(userIn[:userIn.index(" ")])
	del userIn[:userIn.index(" ")+1]
	B.append(userIn[:userIn.index(" ")])
	T.append(userIn[userIn.index(" ")+1:])