n = int(input())
bills = [1, 5, 10, 20, 100]


# still kinda too slow.... especially for a billion!
def min_bills(n):
    min = {}
    min[0] = 0
    for i in range (1,n + 1):
        min_i = float('inf')
        for bill in bills:
            if i - bill >= 0:
                if min[i - bill] < min_i:
                    min_i = min[i - bill]
        min[i] = min_i + 1
    return min[n]


# too slow!

# memo = {}
# def recursive_min_bills(x):
#     if x in bills:
#         return 1
#     elif x in memo:
#         return memo[x]
#     else:
#         least_bills = float('inf')
#         for bill in bills:
#             if x - bill > 0:
#                 result = recursive_min_bills(x - bill)
#                 if result < least_bills:
#                     least_bills = result
#         memo[x] = 1 + least_bills
#         return memo[x]

# cheeky optimisation
highest_bill = max(bills)

times = int(n / highest_bill)

print(min_bills(n - times * highest_bill) + times)