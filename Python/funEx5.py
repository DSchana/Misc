# funEx5.py

def knightMove(x,y):
    pos = []
    pos.append((x+2,y+1))
    pos.append((x+2,y-1))
    pos.append((x-2,y+1))
    pos.append((x-2,y-1))
    pos.append((x+1,y+2))
    pos.append((x-1,y+2))
    pos.append((x+1,y-2))
    pos.append((x-1,y-2))

    for i in range(len(pos)):
        if pos[i][0]>8 or pos[i][0]<0 or pos[i][1]>8 or pos[i][1]<0:
            del pos[i]

    return pos
