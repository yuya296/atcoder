from ast import Str
from itertools import groupby

S = input()
T = input()

def runLengthEnc(s):
    grouped = groupby(s)
    res = []
    for k, v in grouped:
        res.append((k, int(len(list(v)))))
    return res

def check(sl, tl):
    lens = len(sl)
    if (lens != len(tl)):
        return False

    for i in range(lens):
        if (sl[i][0] != tl[i][0]):
            return False
        if (sl[i][1] > tl[i][1]):
            return False
        if (sl[i][1] == 1 and tl[i][1] > 1):
            return False
    
    return True

SRL = runLengthEnc(S)
TRL = runLengthEnc(T)

print("Yes" if check(SRL, TRL) else "No")