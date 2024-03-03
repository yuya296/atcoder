from operator import itemgetter
N, X, Y, Z = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

passed = []
all_students = [(A[i],B[i],A[i]+B[i], i+1) for i in range(N)]

all_students.sort(reverse=True,key=lambda x: x[0])
passed.extend(all_students[:X])
all_students = all_students[X:]

all_students.sort(key=lambda x: x[3])
all_students.sort(reverse=True,key=lambda x: x[1])
passed.extend(all_students[:Y])
all_students = all_students[Y:]

all_students.sort(key=lambda x: x[3])
all_students.sort(reverse=True,key=lambda x: x[2])
passed.extend(all_students[:Z])

passed.sort(key=lambda x: x[3])

for v in passed:
    print(v[3])