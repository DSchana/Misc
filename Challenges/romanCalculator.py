nums = {
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1 }

def romanToInt(r_num):
    num = 0
    p_l = -2  # Previous location
    l = -1    # Current location

    for n in nums.keys():
        start = 0
        num_count = 0

        while num_count != r_num.count(n):        
            l = r_num.find(n, start)
            start = l

            if l == -1:
                continue

            v = 0  # Value to add
            for i in range(l, min(l + 3, len(r_num))):
                if r_num[i] == n:
                    num_count += 1
                    start += 1
                    v += nums[n]
                else:
                    break

            if l > p_l:
                num += v
            else:   
                num -= v

            p_l = l

    return num

def intToRoman(num):
    r_num = ""

    for n in nums.keys():
        if nums[n] > num:
            continue

    return r_num

print(romanToInt("XCIX"))
print(intToRoman(54))
