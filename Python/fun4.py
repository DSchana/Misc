# fun4.py
# create a function called dotDiamond(n) that outputs a diamond
# of dots.

def dotDiamond(n):
    for i in range(1,n+1):
        line(n,i)

    for i in range(n-1,0,-1):
        line(n,i)

def line(full,num):
    sp = full-num
    dots = (num*2)-1
    print(" "*sp + "*"*dots)

dotDiamond(7)
