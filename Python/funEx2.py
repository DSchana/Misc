# funEx2.py

def palindrome(pal):
    pal = pal.upper()

    lets = [c for c in pal if "a" <= c <= "z"]
    
    return lets == lets[::-1]

print(palindrome("Race,Car"))
