from math import gcd

N = int(input())
A = list(map(int, input().split()))
max_val = max(A)

def check(m):
    ans = A[0] % m
    for i in range(1,N):
        if (ans != A[i] % m):
            # print(str(m) + " is not passed")
            return False
    # print(str(m) + " is passed")
    return True

def exec():
    for m in range(3,max_val+1):
        if check(m):
            return True
    return False

print(1 if exec() else 2)