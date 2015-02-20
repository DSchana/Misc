# funEx6.py

def persistence(n):
    if n < 10:
        return 0
    else:
        n2 = eval("*".join(list(str(n))))
        return 1+persistence(n2)

print(persistence(55))
