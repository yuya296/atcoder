# 入力 ===========
import itertools


H1, W1 = map(int, input().split())
A = []
for i in range(H1):
    A.append(list(map(int, input().split())))

H2, W2 = map(int, input().split())
B = []
for i in range(H2):
    B.append(list(map(int, input().split())))

# 処理 ============
lst = []
result = False


for ih in itertools.combinations(range(H1),H2):
    for iw in itertools.combinations(range(W1),W2):
        # print(ih, iw)
        judge = True
        for ih2 in range(H2):
            for iw2 in range(W2):
                if A[ih[ih2]][iw[iw2]] != B[ih2][iw2]:
                    judge = False
        if judge:
            result = True

print('Yes' if result else "No")
