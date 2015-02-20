# Banananas.py
from functools import *

@lru_cache()
def aWord(word):
    if word == "A":
        return True
    elif len(word) > 2 and word[0] == "B" and word[-1] == "S":
        return mWord(word[1:-1])
    else:
        return False

@lru_cache()
def mWord(word):
    if aWord(word):
        return True
    else:
        monkey = False
        for i in range(1,len(word)-1):
            if word[i] == "N":
                if aWord(word[:i]) and mWord(word[i+1:]):
                    monkey = True
        return monkey

while True:
    word = input()
    if word == "X":
        break

    print("YES" if mWord(word) else "NO")
