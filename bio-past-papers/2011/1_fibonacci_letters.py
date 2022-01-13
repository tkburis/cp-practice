a, b, n = input().split()
n = int(n)

if n == 1:
    print(a)
elif n == 2:
    print(b)
else:
    curr = (ord(a) - ord('A') + ord(b) - ord('A') + 1) % 26 + 1
    prev = ord(b) - ord('A') + 1
    for _ in range(n-3):
        curr = (curr + prev - 1) % 26 + 1
        prev = (curr - prev)
    print(chr(curr + ord('A') - 1))

