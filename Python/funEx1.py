# funEx1.py

def menu():
    print("""Food
__________________
1. Fries
2. Pig burger
3. Cow burger
4. Peacock stew
5. Chips""")
    food = input("Pick one: ")
    return food

food = menu()
print("You chose", food)
