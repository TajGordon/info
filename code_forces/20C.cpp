#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    unordered_map<int, tuple<int,int>> distance;
    {
        vector<map<int,int>> edges(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b, w; cin >> a >> b >> w;
            if (!edges[a].count(b) || edges[a][b] > w)
            {
                edges[a][b] = w;
                edges[b][a] = w;
            }
        }
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int,int>>> pq;
        for (int i = 1; i < n + 1; i++)
        {
            pq.push({INT_MAX, i});
            distance[i] = {INT_MAX,0};
        }
        distance[1] = {0,0};
        pq.push({0, 1});
        /* can have multiples edges per pair of nodes, and loops */
        set<int> unvisited;
        for (int i = 1; i < n + 1; i++)
        {
            unvisited.insert(i);
        }
        while (pq.size())
        // while (unvisited.size())
        {
            auto [cost, node] = pq.top();
            // int cost = INT_MAX;
            // int node = 0;
            // for (auto i : unvisited)
            // {
            //     if (get<0>(distance[i]) < cost) 
            //     {
            //         cost = get<0>(distance[i]);
            //         node = i;
            //     }
            // }
            pq.pop();
            if (!unvisited.count(node)) continue;
            unvisited.erase(node);
            for (auto [neighbor, edge_cost] : edges[node])
            {
                if (!unvisited.count(neighbor)) continue;
                if (cost + edge_cost < get<0>(distance[neighbor]))
                {
                    distance[neighbor] = {cost + edge_cost, node};
                    pq.push({cost + edge_cost, neighbor});
                }
            }
        }
    }
    if (get<0>(distance[n]) != INT_MAX)
    {
        stack<int> path;
        path.push(n);
        while (path.top() != 1)
        {
            int node = path.top();
            path.push(get<1>(distance[node]));
        }
        while (path.size() > 0)
        {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
    else cout << "-1" << endl;
}