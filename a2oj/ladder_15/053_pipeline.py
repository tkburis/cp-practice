from math import ceil, sqrt

n, k = map(int, input().split())
if n-k == 1:
    print(2)
else:
    discrim = (1-2*k)**2-8*n+8
    if discrim < 0:
        print(-1)
    else:
        x = int(ceil((-1+2*k-sqrt(discrim))/2))
        if x >= k:
            print(-1)
        else:
            print(x)
