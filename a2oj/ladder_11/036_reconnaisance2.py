# https://codeforces.com/problemset/problem/34/A

n = int(input())
a = list(map(int, input().split()))
mins = []
for i in range(len(a)):
    mins.append(abs(a[i] - a[(i+1) % n]))

for i in range(len(mins)):
    if mins[i] == min(mins):
        if i == len(mins)-1:
            print(len(mins), 1)
        else:
            print(i+1, i+2)
        break