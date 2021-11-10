# https://codeforces.com/problemset/problem/141/A

a = input()
b = input()
c = sorted(input())
s = sorted(a + b)
if c == s:
    print("YES")
else:
    print("NO")
