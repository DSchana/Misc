# file I/O file input output
numFile = open("nums.txt", "r")
text = numFile.read()  # reads whole file as one string
print(text)
print(repr(text))  # shows all characters incuding \n etc.
numFile.close()
tot = 0
for n in text.split():
    tot += int(n)
print(tot)

#read() - reads file as one string

#readline() - reads one line at a time from file. Good if data
# in file is hterogeneous (use this for contests)

#readlines - reads whole file as a list of strings, one per line

# lines = open("names.txt", "r").read().strip().split("\n")
# better than readlines
