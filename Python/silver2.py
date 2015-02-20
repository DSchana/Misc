# silver2.py

n = int(input())
word = input()
letters = []

for i in range(n):
    rep = word.count(word[i])
    if rep%2 == 1:
        word.replace(word[i]," ")

for i in range(n):
    if word[i] != " ":
        letters.append(word[i])

print(letters, len(letters))
