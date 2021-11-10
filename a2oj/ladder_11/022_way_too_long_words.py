# https://codeforces.com/problemset/problem/71/A

n = int(input())
for _ in range(n):
    s = input()
    if len(s) <= 10:
        print(s)
        continue
    print(f'{s[0]}{len(s)-2}{s[-1]}')
