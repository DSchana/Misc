def isPalindrome(p):
    for i in range(len(p) // 2):
        if p[i] != p[len(p) - 1 - i]:
            return False
    return True

s = input().lower()

print(isPalindrome(s))