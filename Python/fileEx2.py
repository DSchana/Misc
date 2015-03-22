course = input()

names = open("File Exercise Data/classes.txt", "r").read().strip().split("\n")
others = open("File Exercise Data/"+course+".txt", "w")

for name in names:
    if course in name:
        others.write(name.split(",")[0] + " " + name.split(",")[1])
others.close()
