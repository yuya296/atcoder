from telnetlib import NOP


N, M, E = map(int, input().split())
U, V = [], []
for i in range(E):
    U[i], V[i] = map(int, input().split())
Q = int(input())
X = []
for i in range(Q):
    X[i] = int(input())

# 処理 ======
parent = [i for i in range(N+M)]
# root = [parent[i] for i in range(N+M)]
# root_list = [False for _ in range(N+M)]

in_lighting = [(i < N) for i in range(N+M)]

add_path = reversed([(U[x], V[x]) for x in X])


def root(x):
    return x if parent[x] == x else root(parent[x])

def unite(x, y):
    rx = root(x)
    ry = root(y)
    parent[rx] = ry

def same(x, y):
    rx = root(x)
    ry = root(y)
    return rx == ry

for i in range(E):
    if not i+1 in X:
        unite(U[i]-1,V[i]-1)

for i in reversed(X):
    u = U[i-1] -1
    v = V[i-1] -1
    if same(u,v):
        pass
    else if 