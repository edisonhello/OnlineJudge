n = int(input())
a = list(map(int, input().split()))

maxn = 5000 + 5
dp = [[0 for i in range(maxn)] for j in range(maxn)]

for i in range(n):
    
