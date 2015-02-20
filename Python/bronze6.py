word1 = list(input().lower()).sort()
word2 = list(input().lower()).sort()

for i in range(len(word1)-1,-1,-1):
    if word1[i] == " ":
        del word1[i]

for i in range(len(word2)-1,-1,-1):
    if word2[i] == " ":
        del word2[i]

if word1 == word2:
    print("yes")
else:
    print("no")
