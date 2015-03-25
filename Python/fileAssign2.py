from random import *

def clean(line):
	for p in ':;.,\"?!()[]-_':
		line = line.replace(p, "")
	return line

countries = []
capitals = []

file = open("File assignment data/capitals.txt", "r").read().strip()
file = clean(file).split("\n")

for i in file:
	countries.append(i[:i.index(" ")])
	capitals.append(i[i.index(" ")+1:])

for i in range(10):
	correct = randint(1, len(countries))
	c_cont = countries[correct]
	c_cap = capitals[correct]
	wrongs = []
	for i in range(3):
		wrongs.append(capitals[randint(1, len(countries))])