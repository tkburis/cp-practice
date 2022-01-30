n = int(input())
obs = []
for _ in range(n):
    obs.append(list(map(int, input().split())))
obs = sorted(obs)
maxi = 0
for i in range(n-1):
    maxi = max(maxi, (abs(obs[i][1] - obs[i+1][1]) / (obs[i+1][0] - obs[i][0])))
print(maxi)
