# funEx4.py

def letterMark(mark):
    if mark < 50:
        return "F"
    elif mark < 60:
        return "D"
    elif mark < 70:
        return "C"
    elif mark < 80:
        return "B"
    else:
        return "A"

print(letterMark(76))
