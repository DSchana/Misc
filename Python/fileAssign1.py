# Dilpreet Chana
# fileAssign1.py
# The file reads a story and determines if they are in the dictionary

def clean(line):
	"Removes any unwanted punctuation"
    for p in ''':;.,"'?!()\[]_''':
        line = line.replace(p, "")
    line = line.replace("-", " ")
    return line

dictionary = set(open("File assignment data/dictionary.txt", "r").read().strip().lower().split())  # read the dicionary
story = open("File assignment data/story.txt", "r").read().strip().lower()  # read the story
story = clean(story).split()  # clean the story of punctuation
good = []

# Loop checks all the words in story against dictionary
for word in set(story):
    word.strip("'")
    if word not in dictionary:
        print(word)

# Dilpreet Chana
# fileAssign2.py
# Program quizzes user on the capital of 196 countries

from random import *

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


# Dilpreet Chana
# fileAssign3.py
# Program creates a python file to display an image

from pygame import *

outFile = open("File assignment data/image.py", "w")

picture = image.load("File assignment data/dc.png")

outFile.write('''from pygame import *
screen = display.set_mode((%d, %d))\n
''' % (picture.get_width(), picture.get_height()))

for x in range(0, picture.get_width(), 2):
	for y in range(0, picture.get_height(), 2):
		col = picture.get_at((x, y))
		r = col[0]
		g = col[1]
		b = col[2]
		outFile.write("draw.circle(screen, (%d, %d, %d), (%d, %d), 2)\n" % (r, g, b, x, y))
outFile.write('''
display.flip()
done = False
while done == False:
	for e in event.get():
		if e.type == QUIT:
			done = True''')

outFile.close()


# Dilpreet Chana
# fileAssign4.py
# Program creates an html file that displays all images of a specific
# extention, eg. *.png in a table

import glob

pics = glob.glob("File assignment data/*.png")

outFile = open("File assignment data/pics.html", "w")

outFile.write("""
<!DOCTYPE html>
<html>
  <head>
	<title>
      Pictures
  </title>
  </head>
  <body>
	<table border = 1 cellpadding = 5>""")

if len(pics) % 2 == 1:
	pics.append("\\")

for i in range(0, len(pics), 2):
	print(pics[i][pics[i].index("\\")+1:], pics[i+1][pics[i+1].index("\\")+1:])
	outFile.write("<tr><td>%s</td><td>%s</td></tr>\n" % (pics[i][pics[i].index("\\")+1:], pics[i+1][pics[i+1].index("\\")+1:]))
	outFile.write('\t<tr><td><img src="%s" alt="image" style="width:480px;height:360px"></td><td><img src="%s" alt="image" style="width:480px;height:360px"></td></tr>\n' % (pics[i][pics[i].index("\\")+1:], pics[i+1][pics[i+1].index("\\")+1:]))

outFile.write("</table></body></html>")
outFile.close()