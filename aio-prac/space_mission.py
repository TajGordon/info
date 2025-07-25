n, f = map(int, input().split())
c = []
for i in range(n):
    a = int(input())
    c.append(a)

# # find max sized window where c_start + c_end <= f
# # brute force with window could work
# start = 0
# length = n
# found = False

# while length > 1 and not found:
#     for i in range(n - (length-1)):
#         if c[i] + c[i + length-1] <= f:
#             found = True
#             break
#     if found:
#         break
#     else: 
#         length -= 1

# if length <= 1:
#     print('-1')
# else:
#     print(length)


# grower approach?
# start from the middle 2 indices, and go right/left to the lowest cost (to the right of the index)
# or maybe start from 2 lowest costs, and then find the rightmost and leftmost that fit (max distance per cost), and make that one, and repeat?
l = n // 2 - 1
r = n // 2
running = True
while l >= 0 and r < n and running:
    furthest_right_that_fits = None
    for i in range(1,n - r):
        if c[l] + c[i + r] <= f: # if it fits
            furthest_right_that_fits = i + r
    furthest_left_that_fits = None
    for i in range(1,l + 1):
        if c[r] + c[l - i] <= f: # if it fits
            furthest_left_that_fits = l - i
    if furthest_left_that_fits == None and furthest_right_that_fits != None:
        r = furthest_right_that_fits
    elif furthest_left_that_fits != None and furthest_right_that_fits == None:
        l = furthest_left_that_fits
    elif furthest_left_that_fits != None and furthest_right_that_fits != None:
        if abs(l - furthest_left_that_fits) > abs(r - furthest_right_that_fits):
            l = furthest_left_that_fits
        elif abs(l - furthest_left_that_fits) < abs(r - furthest_right_that_fits):
            r = furthest_right_that_fits
        else:
            if c[furthest_left_that_fits] < c[furthest_right_that_fits]:
                l = furthest_left_that_fits
            else:
                r = furthest_right_that_fits
    else:
        running = False
        break

if (r - l) <= 1:
    print('-1')
else:
    print(r - l + 1)