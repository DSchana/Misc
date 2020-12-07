def maxMatching(X, Y, E):
    '''
    X - First partite set with vertices labeled with numbers
    Y - Second partite set with vertices labeled with numbers
    E - Edge set with unordered pairs from X and Y
    '''

    M = {}  # m[x] = y -> x matches with y
    S = [False] * len(X)
    marked = []

    # initialize all matches to null
    for x in X:
        M[x] = None

    max_matching_found = False

    while not max_matching_found:
        term = False

        for x in X:
            # Consider every unmarked x in X
            if x not in marked:
                # Find neighbours of x in Y from the edge set E
                ns = []
                for e in E:
                    if e[0] == x:
                        ns.append(e[1])
                    elif e[1] == x:
                        ns.append(e[0])

                for y in ns:
                    if M[x] != y and y not in M.values():
                        # For all neighbours of x, if y is unsaturated by M
                        # Then add xy to M and terminate this iteration

                        M[x] = y
                        term = True
                        break
                    else:
                        # If y is already saturated by M then it is already matched to some x
                        # so we add that to S
                        for i in range(len(X)):
                            if M[X[i]] == y:
                                S[i] = True
                                break

                marked.append(x)  # Mark x after x has been considered

            # Terminate current iteration
            if term:
                break

        # Once all x in X have been considered a maximum matching is found
        if len(marked) == len(X):
            max_matching_found = True

    # Return edges in the same format they were provided
    ret = []
    for x in X:
        if M[x] == None:
            del M[x]
        else:
            ret.append((x, M[x]))

    return ret

X = [0, 1, 2, 3, 4, 5, 6, 7, 8]
Y = [9, 10, 11, 12, 13, 14, 15, 16]
E = [(0, 9),
     (1, 9),
     (2, 10),
     (3, 9),
     (4, 9), (4, 10), (4, 11),
     (5, 10), (5, 11),
     (6, 11), (6, 12),
     (7, 10), (7, 13), (7, 15),
     (8, 10), (8, 14), (8, 16)]

M = maxMatching(X, Y, E)
print(len(M), M)