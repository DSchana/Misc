# file5.py

from random import *

names = open("ICS3U-03.txt", "r").read().strip().split("\n")
rpsFile = open("rps.html", "w")

if len(names)%2 != 0:
    names.append("Mr.McKenzie")
shuffle(names)

rpsFile.write("""<html><head><title>RPS week 1</title></head>
				 <body>
				 <h1>RPS Tournament</h1>
				 <table border = 1 cellpadding = 5>
				 """)
line = "<tr><td>%s</td><td>Vs.</td><td>%s</td></tr>"

for i in range(0, len(names)-1, 2):
    rpsFile.write(line % (names[i].split()[0], names[i+1].split()[0]))

rpsFile.write("</table></body></html>")

rpsFile.close()