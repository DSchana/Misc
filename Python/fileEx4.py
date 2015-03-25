def clean(line):
	for p in ':;.,\"?!':
		line = line.replace(p, "")
	return line

story = open("File Exercise Data/story.txt", "r").read().strip().lower()
story = clean(story).split()

freq = []
words = []

for word in story:
	word = word.strip("'")
	if word not in words:
		words.append(word)
		freq.append((story.count(word), word))

freq.sort(reverse = True)

outFile = open("File Exercise Data/frequency.txt", "w")

for fr,wrd in freq:
	outFile.write("%-20s%3d\n" % (wrd, fr))

outFile.close()