import math
A, B = map(int, input().split())

def calc(dg):
    if dg == -1: 
        return 10**19
    return A / ((1+dg)**0.5) + dg*B

v = (A/(2*B))**(2/3) - 1

p1 = math.ceil(v)
p2 = math.floor(v)

ans1 = calc(p1)
ans2 = calc(p2)
print(min(ans1,ans2))