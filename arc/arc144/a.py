N = int(input())

def f(n):
    i = n
    sum = 0
    while i > 0:
        sum += i%10
        i %= 10

ls = []
