import math
from collections import deque

N = int(input())
sx, sy, tx, ty = map(int, input().split())

x = [0] * N
y = [0] * N
r = [0] * N
for i in range(N):
    x[i], y[i], r[i] = map(int, input().split())

# どの円上にあるのかcheck
start = []
goal = []
for i in range(N):
    if (x[i]-sx)**2 + (y[i]-sy)**2 == r[i]**2:
        start.append(i)
    if (x[i]-tx)**2 + (y[i]-ty)**2 == r[i]**2:
        goal.append(i)

# パスのリスト作成
path = [[] for _ in range(N)]
# for i in range(N):
#     for j in range(i+1,N):
#         d = math.sqrt((x[i]-x[j])**2 + (y[i]-y[j])**2)
#         if (abs(r[i]-r[j]) <= d <= r[i]+r[j]):
#             path[i].append(j)
#             path[j].append(i)

for i in range(N):
    for j in range(i+1,N):
        d2 = (x[i]-x[j])**2 + (y[i]-y[j])**2
        if (abs(r[i]-r[j])**2 <= d2 <= (r[i]+r[j])**2):
            path[i].append(j)
            path[j].append(i)

seen = [False for _ in range(N)] #訪問済み
que = deque([])

for s in start:
    seen[s] = True
    que.append(s)

while len(que) > 0:
    now = que.popleft()
    for p in path[now]:
        if not(seen[p]):
            que.append(p)
            seen[p] = True

judge = False
for g in goal:
    if seen[g]:
        judge = True

print("Yes" if judge else "No")