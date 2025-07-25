
N = int(input().strip())
A = input().strip()
B = input().strip()

max = 0

var = 0

for i in range(2*N):
    if A[i] == 'D' and B[i] == 'R':
        var += 1
    if A[i] == 'D' and B[i] == 'D':
        var += 0
    if A[i] == 'R' and B[i] == 'R':
        var += 0
    if A[i] == 'R' and B[i] == 'D':
        var -= 1
    if var > max: max = var
    
print(max)