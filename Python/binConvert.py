n = int(input())
bit = 128
bNum = 0
while bit!=0:
    if n>=bit and n%bit:
        bNum+=bit
    bit /= 2
    if bit == 1:
        bit = 0

print(bNum)
