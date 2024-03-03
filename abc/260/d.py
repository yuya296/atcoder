import bisect

N, K = map(int, input().split())
P = list(map(int, input().split()))

result = [-1 for _ in range(N)]
field = []


def insert(i,n):
    while len(field) > i and  len(field[i]) >= K:
        i += 1
    if i == len(field):
        field.append([x])
    else:
        field[i].append(n)




for i in range(N):
    x = P.pop(0)
    if len(field) == 0:
        field.append([x])
        if (K == 1):
            field.pop(0)
            result[x-1] = i+1
    else:
        idx = bisect.bisect([y[-1] for y in field], x)
        insert(idx,x)
        # if (idx == len(field)):
        #     field.append([x])
        # else:
        #     field[idx].append(x)

        if len(field[idx]) >= K:
            poped = field.pop(idx)
            for pp in poped:
                result[pp-1] = i+1
    
for r in result:
    print(r)

