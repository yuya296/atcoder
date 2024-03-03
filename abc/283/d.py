from collections import deque
S = input()

alphabet = [-1 for _ in range(26)]
alphabetQue= deque([])

flag = True
for i in range(len(S)):
    if S[i] == '(':
        alphabetQue.append(alphabet.copy())
    elif S[i] == ')':
        alphabet = alphabetQue.pop()
    else:
        if alphabet[ord(S[i])-ord('a')] == -1:
            alphabet[ord(S[i])-ord('a')] = i
        else:
            flag = False
            break

print('Yes' if flag else 'No')

