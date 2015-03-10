# zeros.py
from functools import *

@lru_cache()
def factorial(n):
    if n <= 1:
        return 1
    else:
        return n*factorial(n-1)

n = int(input())
print(str(factorial(n)).count("0"))
