



# TLE'd with python, maybe in cpp?
# cpp TLE'd on one fucking case
# need binary search for answer to meet time complexity
# --> this isn't what the guy did on the doc, 
# he did something where he resized the checking using logic
# maybe i should try to implement that...



c, n, k = map(int, input().split()) # ints

chairs = input() # 'd' or 'w'

def csws(size):
    p = 0
    nws = 0
    for i in range(p, p + size):
        nws += 1 if chairs[i] == 'w' else 0

    if (size - nws) >= (n - k):
        return True

    for i in range(1, c - size + 1):
        p += 1
        nws -= 1 if chairs[p - 1] == 'w' else 0
        nws += 1 if chairs[p + size - 1] == 'w' else 0
        if (size - nws) >= (n - k):
            return True
    
    return False

# # iterative approach
# for i in range(n, c + 1):
#     if csws(i):
#         print(i)
#         break

# binary search approach
left = 0
right = c
ss = -1
while left <= right:
    mid = int((left + right) / 2)
    if mid < n:
        mid = n
        if (csws(n)):
            ss = n
            break
    if (csws(mid)):
        ss = mid
        right = mid - 1 # - 1 so it moves from repeating the same case
    else:
        left = mid + 1
    

print(ss)
        
