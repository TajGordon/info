# connected undirected graph
# nodes have types (an int)
# paths exist between every pair of nodes with the same type
# destroy 1 edge to make the most amount of paths become impossible
# to disconnect the most amount of nodes with the same type
# shipment route can go over nodes of wrong type
# therefore as long as a node is connected, the shipment route is possible
# if there are n connected nodes of a type t, than that makes s= n(n-1)/2 paths
# so if we disconnect 2 nodes, we go to s - (n-2)((n-2)-1)/2 disconnects (old amount - new amount = amount we took) + amount still present in new graph (which is still connected)
# maximise the number of disconnects
# for each type, with n_t nodes, minimisie(max(n_t)) for all t, that is, disconnecting nodes with a higher count is better
# what edge can i remove to disconnect the most amount of nodes
# for each edge that connects 2 disconnected subgraphs, what is the s(n) - s(n') + s(n'')
# 

n, m = map(int, input().split())
l = list(map(int, input().split()))
e = {}
for i in range(n):
    x,y = map(int, input().split())
    if not e[x]:
        e[x] = []
    if not e[y]:
        e[y] = []
    e[x].append(y)
    e[y].append(x)
