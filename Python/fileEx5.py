from random import *

num = randint(1, 100)
userGuess = 0
guesses = 0

while userGuess != num:
	userGuess = int(input())
	guesses += 1
	if userGuess < num:
		print("Higher")
	if userGuess > num:
		print("Lower")
print("Correct")

scores = open("File Exercise Data/high scores.txt", "r").read().strip().split("\n")
scores.append(str(guesses)+" "+str(num))
scores.sort()
if len(scores)>10:
        del scores[10]
        
highFile = open("File Exercise Data/high scores.txt", "w")
for i in scores:
        highFile.write(i+"\n")
highFile.close()
