words = open("File Exercise Data/story.txt", "r").read().strip().split()
unique = []
count = []

for word in words:
	if word not in unique:
		unique.append(word)

freq = open("File Exercise Data/frequency.txt", "w")

for i in range(len(unique)):
	count.append(words.count(word))
	unique[i][1] = str(count[i])

unique.sort()

for i in range(len(unique)):
	print(unique[i][0], unique[i][1])

freq.close()