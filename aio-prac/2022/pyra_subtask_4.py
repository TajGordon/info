from collections import defaultdict


n = int(input())
p = list(map(int, input().split()))

dp = [1] * (n // 2 )
max_len = 0
max_idx = [0]
for i in range(1, n//2):
    if p[i] == p[i-1] + 1:
        dp[i] = dp[i-1] + 1
        if dp[i] > max_len:
            max_len = dp[i]
            max_idx = [i]
        elif dp[i] == max_len:
            max_idx.append(i)
        
done = False
for i in max_idx:
    if p.count(p[i] + 1) > 0:
        print(n - (2 * max_len + 1))
        done = True
        break

if not done:
    print(n - (2 * max_len - 1))