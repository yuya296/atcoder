import copy 

N, M = map(int, input().split())
A = list(map(int, input().split()))

# for i in range(M):
#     A2 = A[:i] + A[i+1:]
#     now = 1
#     for idx in range(M-1):
#         if A2[idx] == now:
#             now += 1
#         elif A2[idx] == now-1:
#             now = now - 1
#     print(now)
