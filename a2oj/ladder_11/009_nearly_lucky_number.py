# https://codeforces.com/problemset/problem/110/A

n = input()
num_lucky = n.count('4') + n.count('7')
if set(str(num_lucky)).union({'4', '7'}) == {'4', '7'}:
    print('YES')
else:
    print('NO')
