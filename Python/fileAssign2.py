# Dilpreet Chana
# fileAssign2.py
# Program quizzes user on the capital of 196 countries

from random import *
#brownboy
def clean(line):
	"Removes any unwanted punctuation"
	for p in ':;.,\"?!()[]-_':
		line = line.replace(p, "")
	return line

countries = []  # Holds all the countries
capitals = []  # Holds all the capitals
rights = 0

file = open("File assignment data/capitals.txt", "r").read().strip().split("\n")

# for loop separates capitals from countries
for i in file:
	countries.append(i[:i.index("-")-1])
	capitals.append(i[i.index("-")+2:])

for i in range(10):
	correct = randint(1, len(countries))
	c_cont = countries[correct]
	c_cap = capitals[correct]
	answers = []
	for i in range(3):
		answers.append(capitals[randint(1, len(countries))])
	answers.append(c_cap)
	shuffle(answers)

	print("What is the capital of", c_cont+"?")
	for i in range(4):
		print("%d. %-10s" % (i+1, answers[i]))

	userIn = input()
	if userIn == c_cap:
		print("Correct")
		rights += 1
	else:
		print("Wrong, the answer is", c_cap)

print(str(rights*10) + "%")
