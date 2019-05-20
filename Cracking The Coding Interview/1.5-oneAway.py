s1 = input()
s2 = input()

one_away = True

if len(s1) != len(s2):
    one_away = False
if s1 == s2:
    one_away = True
elif len(s1) == len(s2) - 1:
    for s in s1:
        if s not in s2:
            one_away = False
            break
elif len(s1) == len(s2) + 1:
    for s in s2:
        if s not in s1:
            one_away = False
            break
elif len(s1) == len(s2):
    off_count = 0
    for s in s1:
        if s not in s2:
            off_count += 1

        if off_count == 2:
            one_away = False
            break

print(one_away)