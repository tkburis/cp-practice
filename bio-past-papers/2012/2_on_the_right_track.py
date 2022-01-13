class Point:
    def __init__(self, name, flipflop=False, left=None, right=None, straight=None):
        self.name = name
        self.flipflop = flipflop
        self.straight = straight
        self.left = left
        self.right = right
        self.is_left = True

    def set_conns(self, left, right, straight):
        self.left = left
        self.right = right
        self.straight = straight

    def train_enters(self, enters_from):
        if self.flipflop:
            if enters_from == self.straight.name:
                if self.is_left:
                    self.is_left = False
                    return self.left
                else:
                    self.is_left = True
                    return self.right
            return self.straight
        else:
            if enters_from == self.straight.name:
                return self.left if self.is_left else self.right
            if enters_from == self.left.name:
                self.is_left = True
            else:
                self.is_left = False
            return self.straight

points = {}
for i in range(24):
    points[chr(i + ord('A'))] = Point(chr(i+ord('A')))

points['A'].set_conns(points['E'], points['F'], points['D'])
points['B'].set_conns(points['G'], points['H'], points['C'])
points['C'].set_conns(points['I'], points['J'], points['B'])
points['D'].set_conns(points['K'], points['L'], points['A'])
points['E'].set_conns(points['M'], points['N'], points['A'])
points['F'].set_conns(points['N'], points['O'], points['A'])
points['G'].set_conns(points['O'], points['P'], points['B'])
points['H'].set_conns(points['P'], points['Q'], points['B'])
points['I'].set_conns(points['Q'], points['R'], points['C'])
points['J'].set_conns(points['R'], points['S'], points['C'])
points['K'].set_conns(points['S'], points['T'], points['D'])
points['L'].set_conns(points['T'], points['M'], points['D'])
points['M'].set_conns(points['L'], points['E'], points['U'])
points['N'].set_conns(points['E'], points['F'], points['U'])
points['O'].set_conns(points['F'], points['G'], points['V'])
points['P'].set_conns(points['G'], points['H'], points['V'])
points['Q'].set_conns(points['H'], points['I'], points['W'])
points['R'].set_conns(points['I'], points['J'], points['W'])
points['S'].set_conns(points['J'], points['K'], points['X'])
points['T'].set_conns(points['K'], points['L'], points['X'])
points['U'].set_conns(points['M'], points['N'], points['V'])
points['V'].set_conns(points['O'], points['P'], points['U'])
points['W'].set_conns(points['Q'], points['R'], points['X'])
points['X'].set_conns(points['S'], points['T'], points['W'])

flipflops = input()
for x in flipflops:
    points[x].flipflop = True
train_pos = input()
n = int(input())

for _ in range(n):
    train_pos = train_pos[1] + points[train_pos[1]].train_enters(train_pos[0]).name
print(train_pos)

