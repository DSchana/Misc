board = [[j for j in input()] for i in range(16)]
points = [[int(j) for j in input().split(' ')] for i in range(5)]

for x, y in points:
    if board[x][y] == 'X':
        print("MINE - YOU LOST")
        continue

    s_mines = 0
    for i in range(x - 1, x + 2):
        if i < 0 or i >= 30:
            continue

        for j in range(y - 1, y + 2):
            if j < 0 or j >= 16:
                continue

            if board[i][j] == 'X':
                s_mines += 1
