N, M, X, T, D = map(int, input().split())

if (M > X):
    print(T)
else:
    h0 = T - X * D
    print(h0 + D * M)
