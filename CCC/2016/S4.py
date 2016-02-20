n = int(input())
balls = input().split()
found = True

for i in range(n):
    balls[i] = int(balls[i])

while found:
    found = False
    for i in range(len(balls)-1):
        if i+2<len(balls) and balls[i] == balls[i+2]:
            balls[i] = balls[i] + balls[i+1] + balls[i+2]
            del balls[i+2]
            del balls[i+1]
            found = True
            break
        elif balls[i] == balls[i+1]:
            balls[i] = balls[i] + balls[i+1]
            del balls[i+1]
            found = True
            break
        
print(max(balls))
