def magic(n, a, b, c, x, y):
    s = [0]*n
    s[0] = a
    for i in range(1, n):
        s[i] = (s[i-1]*b + a)%c
    r = s.sort()
    v = 0
    for j in range(n):
        v = (v*x + s[j])%y
    return v

print(magic(18291, 1728718, 2819289, 918738, 99738, 372797))
print(magic(99999, 99999999, 22, 33333, 1, 45454545))
