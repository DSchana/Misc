s = input()
s_out = ""

count = 0
curr_char = ''
for c in s:
    if c != curr_char:
        s_out += curr_char + str(count)

        count = 0
        curr_char = c

    count += 1

if len(s_out) >= len(s):
    print(s)
else:
    print(s_out)