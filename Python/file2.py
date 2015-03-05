# writing to a file
from random import *

outFile = open("nums2.txt", "w")
for i in range(10000):
    n = randint(1, 1000)
    outFile.write("%s " % n)
outFile.close()
