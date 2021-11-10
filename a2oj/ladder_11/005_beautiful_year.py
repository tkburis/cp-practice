# https://codeforces.com/problemset/problem/271/A

n = int(input())
while True:
    n += 1
    if len(str(n)) == len(set(str(n))):
        break
print(n)
