s = input()
t = input()
i = 0
j = 0
while i < len(s) and j < len(t):
    if s[i] == t[j]:
        j += 1
    i += 1

if j == len(t):
    print("automaton")
else:
    s_freqs = {}
    for c in s:
        if c not in s_freqs:
            s_freqs[c] = 0
        s_freqs[c] += 1
    t_freqs = {}
    for c in t:
        if c not in t_freqs:
            t_freqs[c] = 0
        t_freqs[c] += 1
    if s_freqs == t_freqs:
        print("array")
    else:
        for k, v in t_freqs.items():
            if k not in s or s_freqs[k] < t_freqs[k]:
                print("need tree")
                break
        else:
            print("both")