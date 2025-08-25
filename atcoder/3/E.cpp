#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() 
{
    int n, q; cin >> n >> q;
    map<int, bool> is_black;
    map<int, set<int>> blacks;
    map<int, int> head;
    for (int i = 1; i <= n; i++)
    {
        is_black[i] = false;
        head[i] = i;
        blacks[i] = {};
    }
    for (int _ = 0; _ < q; _++)
    {
        int t; cin >> t;
        if (t == 1)
        {
            int u, v; cin >> u >> v;
            set_union(blacks[head[u]].begin(), blacks[head[u]].end(), blacks[head[v]].begin(), blacks[head[v]].end(), inserter(blacks[head[u]], blacks[head[u]].begin()));
            blacks[head[v]] = blacks[head[u]];
            blacks[head[u]] = blacks[head[v]];
            head[v] = head[u];
        }
        else if (t == 2)
        {
            int u; cin >> u;
            if (!is_black[u])
            {
                is_black[u] = true;
                blacks[head[u]].insert(u);
            }
            else
            {
                is_black[u] = false;
                blacks[head[u]].erase(u);
            }
        }
        else
        {
            int u; cin >> u;
            if (blacks[head[u]].size() > 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        // cout << "# " << _ << " heads: ";
        // for (int i = 1; i <= n; i++)
        // {
            // cout << head[i] << " ";
        // }
        // cout << endl;
    }
}