s = input().split(";")
a = list(map(int, s[1].split(",")))
b = list(map(int, s[2].split(",")))
c = list(map(int, s[3].split(",")))

a_inv = 0
b_inv = 0
c_inv = 0

for i in range(len(a)):
    for j in range(i + 1, len(a)):
        if a[i] > a[j]: a_inv += 1

for i in range(len(b)):
    for j in range(i + 1, len(b)):
        if b[i] > b[j]: b_inv += 1

for i in range(len(c)):
    for j in range(i + 1, len(c)):
        if c[i] > c[j]: c_inv += 1

if a_inv < b_inv:
    if b_inv < c_inv:
        print("ABC")
    else:
        if a_inv < c_inv:
            print("ACB")
        else:
            print("CAB")
else:
    if a_inv < c_inv:
        print("BAC")
    else:
        if b_inv > c_inv:
            print("CBA")
        else:
            print("BCA")
