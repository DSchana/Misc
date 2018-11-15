n = int(input())

for z in range(n):
    n, k = input().split(' ')

    n = int(n)
    k = int(k)

    curr = bin(int('1' * k + '0' * (n - k), 2))
    end = bin(int('0' * (n - k) + '1' * k, 2))

    print(curr[2:])

    while curr != end:
        curr = bin(int(curr, 2) - 1)

        if curr.count('1') == k:
            print((n - len(curr[2:])) * '0', curr[2:], sep='')
