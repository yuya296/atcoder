import copy
# 入力 ==============
H,W = map(int,input().split())
A = []
for i in range(H):
    A.append(list(map(int,input().split())))

# 定義 ==============
def get_inverted_row(li): # 指定したリストに対して操作を行った行を取得
    return list(map(lambda n:1-n, copy.copy(li)))

def row(h,is_inverted):
    li = copy.copy(A[h])
    return get_inverted_row(li) if is_inverted else li

def check_row(row1, row2, row3):
    for w in range(W):
        num_sames = 0
        if row1 and row2[w]==row1[w]:
            num_sames += 1
        if row3 and row2[w]==row3[w]:
            num_sames += 1
        if w-1 >= 0 and row2[w]==row2[w-1]:
            num_sames += 1
        if w+1 < W and row2[w]==row2[w+1]:
            num_sames += 1
        if num_sames == 0:
            return False
    return True




inf = float('inf')

d = [[[inf,inf],[inf,inf]] for i in range(H)]

d[0][0][0] = 0
d[0][0][1] = 1

for i in range(1,H):
    for j in range(2):
        for k in range(2):
            for l in range(2):
                x = row(i-2, j) if i-2>=0 else None
                y = row(i-1, k)
                z = row(i, l) if i<H else None
                if check_row(x,y,z):
                    d[i][k][l] = min(d[i][k][l], d[i-1][j][k]+l)

ans = inf
# print(d[H-1])
for j in range(2):
    for k in range(2):
        # print(check_row(row(H-2,j),row(H-1,k),None))
        if (check_row(row(H-2,j),row(H-1,k),None)):
            ans = min(ans, d[H-1][j][k])



# ans = min(map(min,d[H-1]))
print(ans if ans<inf else -1)