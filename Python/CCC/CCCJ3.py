# CCCJ3.py

n = int(input())
aRoll = 0
dRoll = 0
a = 100
d = 100

for i in range(n):
    userIn = input()
    aRoll = int(userIn[:userIn.index(" ")])
    dRoll = int(userIn[userIn.index(" ")+1:])
    if aRoll == dRoll:
        pass
    elif aRoll>dRoll:
        d -= aRoll
    else:
        a -= dRoll

print(a)
print(d)
