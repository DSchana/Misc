n,t = input().split()
n = int(n)
t = int(t)
gen = 0
conf = input()

while gen != t:
    tmp = ""
    if conf[1]=="1" and conf[n-1]!="1" or conf[1]!="1" and conf[n-1]=="1":
        tmp += "1"
    else:
        tmp += "0"
        
    for i in range(1, n-1):
        if conf[i-1]=="1" and conf[i+1]!="1" or conf[i-1]!="1" and conf[i+1]=="1":
            tmp += "1"
        else:
            tmp += "0"

    if conf[0]=="1" and conf[n-2]!="1" or conf[0]!="1" and conf[n-2]=="1":
        tmp += "1"  
    else:
        tmp += "0"
    conf = tmp
    gen += 1

print(conf)
