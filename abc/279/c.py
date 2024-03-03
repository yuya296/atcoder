H, W = map(int, input().split())
S = [input() for _ in range(H)]
T = [input() for _ in range(H)]

S2 = sorted([[S[w][h] for w in range(H)] for h in range(W)])
T2 = sorted([[T[w][h] for w in range(H)] for h in range(W)])

print("Yes" if S2 == T2 else "No")