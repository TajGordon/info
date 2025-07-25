#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio();
    int n, m; cin >> n >> m;
    array<vector<int>, 300100> adj;
    vector<int> ric(m);
    for (int i = 0; i < m; i++)
    {
        int k; cin >> k;
        ric[i] = k;
        for (int j = 0; j < k; j++)
        {
            int bj; cin >> bj;
            adj[bj].push_back(i);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int b; cin >> b;
        for (auto p : adj[b])
        {
            ric[i]--;
            if (ric[i] == 0)
            {
                cnt++;
            }
        }
        cout <<  cnt << endl;
    }
}