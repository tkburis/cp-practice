# https://codeforces.com/problemset/problem/61/A

a = input()
b = input()
c = ''

for x, y in zip(a, b):
    if x != y:
        c += '1'
    else:
        c += '0'
print(c)
