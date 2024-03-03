def turn(s):
    turned_list = ['d' if dorp == 'p' else 'p' for dorp in list(reversed(s))]
    return ''.join(turned_list)

N = int(input())
S = input()

L = S.find('p')

max_serial = 0
cnt_serial = 0
idx_serial_last = L
is_in_1 = False
for i in range(L,N):
    if is_in_1:
        if S[i] == 'p':
            cnt_serial += 1
        else:
            is_in_1 = False
            if max_serial < cnt_serial:
                max_serial = cnt_serial
                idx_serial_last = i - 1
    else:
        if S[i] == 'p':
            is_in_1 = True
            cnt_serial = 1

if is_in_1:
    if max_serial < cnt_serial:
        idx_serial_last = N-1

R = idx_serial_last

if L == -1:
    print(S)
else:
    print(S[:L] + turn(S[L:R+1]) + S[R+1:])