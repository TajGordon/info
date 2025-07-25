n, m = map(int, input().split())
t = input()

# frequency of each letter in each position up to n
# count how many times letters appear not in the position n
# n * m == length of t, but only up to n slots
# its a map of alphabet
freq = [{} for _ in range(n)]
# 0 indexed, stores by capital letter

for i in range(n * m):
    if not t[i] in freq[i % n].keys():
        freq[i % n][t[i]] = 1
    else:
        freq[i % n][t[i]] += 1

# got freq list

fs = ""
nc = 0
for i in range(n):
    max = 0
    numnot = 0
    key = None
    for l in freq[i].keys():
        if freq[i][l] > max:
            numnot += max
            max = freq[i][l]
            key = l
        else:
            numnot += freq[i][l]
    fs += key
    nc += numnot

print(nc)
print(fs * m)