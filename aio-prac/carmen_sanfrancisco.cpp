
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, m;
    cin >> n >> m;
    map<unordered_set<int>, vector<int>> edges;
    for (int i = 0; i < m; i++) 
    {
        int x, y, z;
        cin >> x >> y >> z;
        unordered_set<int> s(x, y);
        /* if edge not in set */
        if (!edges.count(s))
        {
            vector<int> v;
            v.push_back(z);
            edges[s] = v;
        }
        else
        {
            edges[s].push_back(z);
        }
    }
    /* we now have the graph */

    int k;
    cin >> k;

    vector<int> cps;
    /* initialise cps */
    for (int i = 1; i < n + 1; i++)
    {
        /* this will probably, hopefully be optimised out somehow by compiler */
        cps.push_back(i);
    }
    vector<int> nps;

    /* propagate graph */
    for (int i = 0; i < k; i++)
    {
        int move;
        cin >> move;
        for (auto edge : edges)
        {
            if (find(edge.second.begin(), edge.second.end(), move) != edge.second.end())
            {
                int makd = 0;
                int first_in = -1;
                int second_in = -1;
                // goes twice, for both nodes in the edge, if either is in cps, then the other is possible
                for (auto city : edge.first)
                {
                    makd++; /* 1, 2 */
                    if (find(cps.begin(), cps.end(), city) != cps.end())
                    {
                        if (makd == 1) first_in = city;
                        if (makd == 2) second_in = city;
                    }
                }
                /* add nodes to graph */
                if (first_in > 0)
                    nps.push_back(first_in);
                if (second_in > 0)
                    nps.push_back(second_in);
            }
        }
        cps = nps;
        nps.clear();
    }

    /* we have the final list */
    for (auto e : cps)
    {
        cout << e << endl;
    }
}