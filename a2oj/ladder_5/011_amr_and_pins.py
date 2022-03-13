from math import ceil

r, x, y, xx, yy = map(float, input().split())

dist = ((xx-x)**2 + (yy-y)**2) ** 0.5
print(ceil(dist/(2*r)))
