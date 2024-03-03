N, X, Y = map(int, input().split())

def red(i):
    if i == 1:
        return 0
    else:
        return red(i-1) + X * blue(i)

def blue(i):
    if i == 1:
        return 1
    else:
        return red(i-1) + Y * blue(i-1)

print(red(N))
