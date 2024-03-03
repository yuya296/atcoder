S = input()


def judge(s1, s2, s3):
    if s1 != s2 and s1 != s3:
        return s1
    if s2 != s1 and s2 != s3:
        return s2
    if s3 != s1 and s3 != s2:
        return s3
    return "-1"

print(judge(S[0], S[1], S[2]))