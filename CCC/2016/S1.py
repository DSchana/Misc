str1 = input()
str2 = input()
arr1 = []
arr2 = []

if str2.find("*") == -1:
    print("N")
elif len(str1) == len(str2):
    for i in range(len(str1)):
        if str2.find(str1[i]) != -1 and str2.count(str1[i])<str1.count(str1[i]) and str2.find("*"):
            str2[str2.index("*")] = str1[i]
        elif str2.find(str1[i]) == -1 and str2.find("*") != -1:
            str2[str2.index("*")] = str1[i]
        elif str2.find(str1[i]) != -1 and str2.count(str1[i])>str1.count(str1[i]):
            print("N")
            quit()
    
    for i in range(len(str1)):
        arr1.append(str1[i])
    for i in range(len(str2)):
        arr2.append(str2[i])

    arr1.sort()
    arr2.sort()
    isIn = True

    for i in range(len(arr2)):
        if arr1.index(arr2[i]) == -1:
            isIn = False
        
    if isIn:
        print("A")
    else:
        print("N")
else:
    print("N")
