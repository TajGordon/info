a, b, k = map(int, input().split())
a,b = min(a,b), max(a,b)
# i < b
mindif = k
used = 0
for i in range(0, b):
    j = (k - (a * i)) // b
    d1 = abs(k - (a * i + b * j))
    u1 = i + j
    d2 = abs(k - (a * i + b * (j+1)))
    u2 = i + j + 1
    d = d1
    u = u1
    if d2 > d1:
        d = d2
        u = u2
    if d < mindif or (d <= mindif and u < used):
        used = u
        mindif = d

print(f"{mindif} {used}")