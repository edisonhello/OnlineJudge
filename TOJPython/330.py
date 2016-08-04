num1 = list(map(int, input().split()))
num2 = list(map(int, input().split()))
a = 0
b = 0
for i in range(0, 4):
    for j in range(0, 4):
        if num1[i] == num2[j]:
            if i == j:
                a += 1
            else:
                b += 1

print(a, 'A', b, 'B', sep='')
