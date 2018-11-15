n = int(input())

for z in range(n):
    m = int(input())

    x = [int(i) for i in input().split(' ')]
    y = [int(i) for i in input().split(' ')]

    dist = 0

    for i in range(len(x)):
        for j in range(len(y) - 1, i - 1, -1):
            if y[j] >= x[i]:
                dist = max(dist, j - i)

    print(dist)
