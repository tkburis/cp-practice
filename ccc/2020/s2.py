# import sys

# sys.stdin = open('C:\\Users\\tkbur\\Desktop\\code\\cp-practice\\ccc\\2020\\input.txt', 'r')
# sys.stdout = open('C:\\Users\\tkbur\\Desktop\\code\\cp-practice\\ccc\\2020\\output.txt', 'w')

m = int(input())
n = int(input())
grid = []
for _ in range(m):
    grid.append(list(map(int, input().split())))

adj = {}
for r in range(m):
    for c in range(n):
        x = (r+1)*(c+1)
        if x not in adj:
            adj[x] = []
        adj[x].append(grid[r][c])
# print(adj)
vis = set()
stack = [1]
while len(stack) > 0:
    curr = stack.pop(0)
    # print('curr', curr)
    if curr == m*n:
        print('yes')
        break
    if curr in adj:
        for nxt in adj[curr]:
            if nxt not in vis: stack.insert(0, nxt)
    vis.add(curr)
    # print(stack)
else:
    print('no')
