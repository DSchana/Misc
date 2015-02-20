# silver 4.py

k = int(input())
coded = input()
decoded = ""
alpha = ['Z','Y','X','W','V','U','T','S','R','Q','P','O','N',
         'M','L','K','J','I','H','G','F','E','D','C','B','A',
         'Z','Y','X','W','V','U','T','S','R','Q','P','O','N',
         'M','L','K','J','I','H','G','F','E','D','C','B','A',]

for i in range(len(coded)):
    shift = 3*(i+1)+k
    loc = alpha.index(coded[i])
    decoded += alpha[loc + shift]

print(decoded)
