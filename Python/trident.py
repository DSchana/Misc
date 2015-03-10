def trident(t, h, s):
    width = 3+(s*2)
    for i in range(1, (t*2)+1):
        if i%2 != 0:
            print("*" + " "*(s) + "*" + " "*(s) + "*")
        else:
            print()
    print("*"*width)

    for i in range(1, 1+h*2):
        if i % 2 == 0:
            print(" "*(width//2) + "*")
        else:
            print()

t = int(input()) # len of prongs
s = int(input()) # spaceing
h = int(input()) # hilt
trident(t, h, s)
