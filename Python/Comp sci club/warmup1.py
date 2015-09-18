# warmup1.py

a = int(input())

min_p = 10000000

for i in range(1, a//2):
	if a % i == 0:
		if (2*i) + (2*(a/i)) < min_p:
			min_p =  (2*i) + (2*(a/i))

print(int(min_p))