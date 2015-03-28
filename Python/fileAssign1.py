def clean(line):
    for p in ''':;.,"'?!()\[]_''':
        line = line.replace(p, "")
    line = line.replace("-", " ")
    return line

dictionary = set(open("File assignment data/dictionary.txt", "r").read().strip().lower().split())
story = open("File assignment data/story.txt", "r").read().strip().lower()
story = clean(story).split()
good = []

for word in set(story):
    word.strip("'")
    if word not in dictionary:
        print(word)
        good.append(word)