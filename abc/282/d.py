N,M = map(int, input().split())
uv = [map(lambda x:int(x)-1, input().split()) for _ in range(M)]
u, v = [list(i) for i in zip(*uv)]

path = [[] for _ in range(N)]
for i in range(M):
    path[u[i]].append(v[i])
    path[v[i]].append(u[i])

black = [0]
white = []
color = [None for _ in range(N)]
while len(black) + len(white) > 0:
    