# moneyPrize.py

def best(x,y,floor):
    if x == 7 and y == 7:
        return floor[7][7]
    else:
        right = 0
        up = 0

        if x < 7:
            right = best(x+1,y,floor)
        if y < 7:
            up = best(x,y+1,floor)

        return floor[x][y]+max(right,up)

floor = [[12, 2, 1, 6, 0, 0, 1, 2],
         [4, 6, 9, 1, 0, 0, 0, 12],
         [0, 4, 5, 7, 7, 7, 4, 5],
         [3, 1, 12, 0, 0, 25, 2, 0],
         [4, 4, 4, 4, 4, 4, 0, 0],
         [1, 10, 3, 0, 0, 2, 12, 3],
         [5, 3, 12, 0, 0, 1, 4, 3],
         [4, 3, 1, 0, 0, 5, 12, 10]]

print(best(0,0,floor))
