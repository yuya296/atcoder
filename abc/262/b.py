N, M = map(int, input().split())

U, V = [], []
path = [[0 for _ in range(N)] for _ in range(N)]
for i in range(M):
    u,v = map(int, input().split())
    U.append(u-1)
    V.append(v-1)

    path[u-1][v-1] = 1
    path[v-1][u-1] = 1


cnt = 0
for i in range(N):
    for j in range(i+1,N):
        for k in range(j+1,N):
            if (path[i][j]==1 and path[j][k]==1 and path[i][k]==1):
                cnt += 1
                # print("(%d,%d,%d)" % (i, j, k))

print(cnt)