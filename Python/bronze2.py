# bronze2.py

n = int(input())
heights = []
ugly = 0

for i in range(n):
    heights.append(int(input()))

for i in range(1,n-1):
    if heights[i+1] <= 41 and heights[i-1] <= 41 and heights[i] <= 41:
        ugly += 1

if heights[0]<=41 and heights[1]<=41:
    ugly += 1

if heights[n-1]<=41 and heights[n-2]<=41:
    ugly += 1

print(ugly)
