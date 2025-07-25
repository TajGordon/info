# safety = how many seconds until you get run over when standing in lane
# only need to be in lane for 1 second (1 instance)
# so maximise the lowest risk
# always go as fast as possible (lowest risk)

# be able to check if possible to get to end from any position and time

# list of all risks (like the windows)
# see if possible to get to one


# get the latest route possible
# then from left-right (lane 0-n)
# update to be most optimal route, valud behind the previous one

# go through the riskiest ones, nad update them


n,m = map(int, input().split())
gaps = {}
for i in range(n):
    a,b,c = map(int, input().split())
    if not a in gaps.keys():
        gaps[a] = []
    gaps[a].append((b,c))

for lane in gaps.keys():
    gaps[lane].sort(key=lambda x : x[0])

# subtask grinding
if m == 1:
    mx = 0
    for s,e in gaps[1]:
        if e - max(s,1) > mx:
            mx = e - max(s,1)
    print(mx)
elif n == m: # only 1 gap
    mni = float('inf')
    t = 0
    for lane in range(1, m+1):
        s,e = gaps[lane][0]
        p = max(s,t + 1)
        if e - p < mni:
            mni = e - p
        t = p + 1
    print(max(mni,0))
else:
    print("0")
