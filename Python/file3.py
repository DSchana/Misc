# say hi to everyone in a text file

names = open("ICS3U-03.txt", "r").read().strip().split("\n")

for name in names:
    print("Greetings", name.split()[0])
