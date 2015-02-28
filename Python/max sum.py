n = int(input())
nums = []
s1=0
s2=0
for i in range(n):
	nums.append(int(input()))
for i in range(0, n, 2):
	s1 += nums[i]
for i in range(1, n, 2):
	s2 += nums[i]

print(max(s1, s2))