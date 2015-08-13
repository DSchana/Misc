from random import *
out = open("picks.txt","w")
mov = map(lambda x:x.split('\t')[2],open("movies.txt").readlines())
kids = map(lambda x:x.replace('"',"").split(',')[:2],open("Trevlac7.txt").readlines())
shuffle(kids)

for l,f in kids:
    out.write(f+","+l+","+choice(mov)+"\n")

out.close()
