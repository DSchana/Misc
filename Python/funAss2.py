def subtract(n1,n2):
    new = []
    for i in n1:
        if i not in n2:
            new.append(i)
    return new

print(subtract([1,2,3,4],[3,4,5,6]))
