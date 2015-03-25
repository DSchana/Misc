def clean(line):
	for p in ':;.,\"?!()[]-_':
		line = line.replace(p, "")
	return line

dictionary = open("File assignment data/dictionary.txt", "r").read().strip().split().lower()
story = open("File assignment data/story.txt", "r").read().strip().lower()
story = clean(story).split()

for word in story:
	word.strip("'")
	if word not in dictionary:
		print(word)