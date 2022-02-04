import sys

sys.stdin = open('C:\\Users\\tkbur\\Desktop\\code\\cp-practice\\ccc\\2021\\input.txt', 'r')
sys.stdout = open('C:\\Users\\tkbur\\Desktop\\code\\cp-practice\\ccc\\2021\\output.txt', 'w')

n = int(input())

heights = list(map(int, input().split()))
widths = list(map(int, input().split()))
total = 0
for i in range(n):
    total += (heights[i] + heights[i+1])/2 * widths[i]
print(f"{total:.1f}")
