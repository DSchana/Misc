# file4.py
# set up RPS tournament
from random import *

names = open("ICS3U-03.txt", "r").read().strip().split("\n")
rpsFile = open("rps.txt", "w")
if len(names)%2 != 0:
    names.append("Mr.McKenzie")
shuffle(names)
for i in range(0, len(names)-1, 2):
    rpsFile.write("%s %s %s\n" % (names[i].split()[0], "Vs.", names[i+1].split()[0]))
rpsFile.close()
