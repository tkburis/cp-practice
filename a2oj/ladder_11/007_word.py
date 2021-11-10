# https://codeforces.com/problemset/problem/59/A

s = input()
num_lows, num_ups = 0, 0
for c in s:
    if c.islower():
        num_lows += 1
    else:
        num_ups += 1
if num_ups < num_lows:
    s = s.lower()
elif num_ups > num_lows:
    s = s.upper()
else:
    s = s.lower()
print(s)
