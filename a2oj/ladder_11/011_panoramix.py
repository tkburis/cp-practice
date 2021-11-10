# https://codeforces.com/problemset/problem/80/A

def is_prime(n):
    for f in range(2, int(n**0.5)+1):
        if n % f == 0:
            return False
    return True


n, m = map(int, input().split())
for i in range(n+1, 51):
    if is_prime(i):
        if m == i:
            print("YES")
        else:
            print("NO")
        break
else:
    print("NO")
