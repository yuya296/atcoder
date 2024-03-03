N, M = map(int, input().split())
S = [input() for _ in range(N)]

count=0
for p1 in range(N):
    for p2 in range(p1+1,N):
        flag = True
        for j in range(M):
            flag &= S[p1][j]=='o' or S[p2][j]=='o'
        if (flag):
            count += 1

print(count)