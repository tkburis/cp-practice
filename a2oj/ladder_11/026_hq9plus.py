# https://codeforces.com/problemset/problem/133/A

p = input()
if any(x in p for x in ('H', 'Q', '9')):
    print("YES")
else:
    print("NO")
