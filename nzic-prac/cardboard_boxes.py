n = int(input())
boxes = []
for i in range(n):
    a = int(input())
    boxes.append(a)

# like a simpler version of the dp one
# need longest increasing, but since no length req, i just sort, and count the number of times the next is strictly bigger than prev
boxes.sort()

counter = 1

for i in range(1,n):
    if boxes[i] > boxes[i-1]:
        counter += 1

print(counter)