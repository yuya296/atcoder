N = int(input())
a = [0] + list(map(int, input().split()))

pairnum = 0
selfnum = 0
for i in range(1,N+1):
    if (a[a[i]] == i and a[i] != i):
        pairnum += 1
    if (a[i] == i):
        selfnum += 1

ans = pairnum / 2 + selfnum*(selfnum-1) / 2
print(int(ans))