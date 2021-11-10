# https://codeforces.com/problemset/problem/275/A

num_pressed = []
for _ in range(3):
    num_pressed.append(list(map(int, input().split())))
num_pressed.insert(0, [0, 0, 0, 0, 0])
num_pressed[1].insert(0, 0)
num_pressed[1].append(0)
num_pressed[2].insert(0, 0)
num_pressed[2].append(0)
num_pressed[3].insert(0, 0)
num_pressed[3].append(0)
num_pressed.append([0, 0, 0, 0, 0])

tot = [[0, 0, 0, 0, 0] for _ in range(5)]

for y in range(1, 4):
    for x in range(1, 4):
        tot[y][x] += num_pressed[y][x] + num_pressed[y][x+1] + num_pressed[y][x-1] + num_pressed[y+1][x] + num_pressed[y-1][x]

truths = []
for i in range(1, 4):
    truths.append([str(int(x % 2 == 0)) for x in tot[i][1:4]])
print("\n".join([''.join(x) for x in truths]))
