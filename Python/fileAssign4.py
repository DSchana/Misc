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