N = int(input())
S = list(input())

flag = False
for i in range(len(S)):
    if (S[i] == '"' ):
        flag = not(flag)
    if (S[i] == ','):
        if (not(flag)):
            S[i] = '.'
print("".join(S))