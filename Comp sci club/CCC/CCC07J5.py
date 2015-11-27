# CCC07J5.py

h = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
a = int(input())
b = int(input())
n = int(input())

for i in range(n):
	h.append(int(input()))

h.sort()

dp = [0]*len(h) 
# dp[i] is # of ways to get to i-th hotel
dp[0] = 1

for i in range(1, len(h)):
	for j in range(i):
		if a <= h[i]-h[j] <= b:
			dp[i] += dp[j]

print(dp[len(h)-1])