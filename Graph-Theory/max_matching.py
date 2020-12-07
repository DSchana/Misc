# X - First partite set with vertices labeled with numbers
# Y - Second partite set with vertices labeled with numbers
# E - Edge set with unordered pairs from X and Y
def maxMatching(X, Y, E):
    M = [E[0]]  # Take one edge as the initial matching to augment

    while True:
        U = X
    
        # U is left with only unsaturated vertices
        for m in M:
            if m[0] in U:
                U.remove(m[0])
            elif m[1] in U:
                U.remove(m[1])

        marked = []  # Track vertices checked

        # Choose and unmarked vertex
        curr = None
        for v in U:
            if v not in marked:
                curr = v

        # If no unmarked vertex can be found, M is a maximum matching
        if curr == None:
            break

        marked.append(curr)

        # Find neighbours of curr in Y
        ns = []
        for e in E:
            if e[0] == curr:
                ns.append(e[1])
            elif e[1] == curr:
                ns.append(e[0])

        # Find neighbour in Y unsaturated by M
        for n in ns:
            is_saturated = False
            for m in M:
                if n in m:
                    is_saturated = True
                    break

            if not is_saturated:
                M.append((curr, n))

    return M

X = [0, 1, 2, 3, 4, 5, 6, 7, 8]
Y = [9, 10, 11, 12, 13, 14, 15, 16]
E = [(0, 9), (1, 9), (3, 9), (4, 9),
     (2, 10), (4, 10), (5, 10), (7, 10), (8, 10),
     (4, 11), (5, 11), (6, 11),
     (6, 12),
     (7, 13),
     (8, 14),
     (7, 15),
     (8, 16)]

M = maxMatching(X, Y, E)
print(len(M), M)
