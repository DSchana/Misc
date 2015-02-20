# silver 3.py

user = input()
n = int(user[0:user.index(" ")])
k = int(user[user.index(" ")+1:])
marks = []
top = []

for i in range(n):
    marks.append(int(input()))

for i in range(k):
    top.append(max(marks))
    del marks[marks.index(max(marks))]

print(sum(top))
