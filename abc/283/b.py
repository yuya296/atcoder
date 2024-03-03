N = int(input())
A = list(map(int, input().split()))
Q = int(input())
query = [list(map(int, input().split())) for _ in range(Q)]

for i in range(Q):
    k = query[i][1]
    if query[i][0] == 1:
        A[k-1] = query[i][2]
    else:
        print(A[k-1])

