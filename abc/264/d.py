S = input()
li = ['atcoder'.find(s) for s in S]
ind = [li.index(i) for i in range(7)]
cnt = 0
for i in range(7):
    cnt += li.index(i) - i
    li.remove(i)
    li.insert(i, i)

print(cnt)