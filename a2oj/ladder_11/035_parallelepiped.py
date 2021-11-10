# https://codeforces.com/problemset/problem/224/A

s1, s2, s3 = map(int, input().split())
a = ((s1*s3)/s2) ** 0.5
b = ((s1*s2)/s3) ** 0.5
c = ((s2*s3)/s1) ** 0.5
print(4*int(a+b+c))
