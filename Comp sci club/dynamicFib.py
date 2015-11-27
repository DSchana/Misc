# dynamicFib.py

num = int(input())

fib = fib[0]*num

fib[1] = fib[2] = 1

for i in range(3, num):
	fib[i] = fib[i-1] + fib[i-2]

print(fib[len-1])