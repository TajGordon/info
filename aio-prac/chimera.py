n = int(input())
a = input()
b = input()
c = input()

failed = False
o = ""

cnt = 0

acnt = 0
bcnt = 0
for i in range(n):
    if a[i] == c[i]:
        acnt += 1
    else:
        break
for i in range(n):
    if b[i] == c[i]:
        bcnt += 1
    else:
        break

prev_was_a = True
maxcnt = acnt
if acnt < bcnt:
    prev_was_a = False
    maxcnt = bcnt

if acnt == n:
    failed = False
elif bcnt == n:
    failed = False
else:
    for i in range(maxcnt, n):
        if prev_was_a:
            if a[i] != c[i]:
                if b[i] != c[i]:
                    failed = True
                    break
                else:
                    prev_was_a = False
                    cnt += 1
        else:
            if b[i] != c[i]:
                if a[i] != c[i]:
                    failed = True
                    break
                else:
                    prev_was_a = True
                    cnt += 1

if failed:
    print("PLAN FOILED")
else:
    print("SUCCESS")
    print(cnt)