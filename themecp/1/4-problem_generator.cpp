#include <bits/stdc++.h>
using namespace std;    
int main()
{
    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        int n, m;
        cin >> n >> m;
        string p;
        cin >> p;
        int f[7] = {};
        for (auto c : p)
        {
            f[c - 65]++;
        }
        int ne = 0;
        for (int i = 0; i < 7; i++)
        {
            ne += max(0, m - f[i]);
        }
        cout << ne << endl;
    }
}