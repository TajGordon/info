#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio();
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<long long> a(n);
        vector<long long> so(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            so[i] = a[i];
        }
        sort(so.begin(), so.end());
        vector<long long> su(n + 1);
        for (int i = 0; i < n; i++)
        {
            su[i+1] = su[i] + so[i];
        }
        vector<long long> gap(n-1);
        for (int i = 0; i < n-1; i++)
        {
            gap[i] = so[i + 1] - su[i + 1];
        }
        map<long long, long long> ma;
        set<long long> vals;
        for (auto e : a)
        {
            vals.insert(e);
        }
        for (int i = 0; i < n-1; i++)
        {
            long long g = gap[i];
            for (auto v : vals)
            {
                if ((v < so[i + 1] && g > 0) || v < g)
                {
                    ma[v] = i;
                    vals.erase(v);
                }
                else if (v == so[i + 1] || v >= g)
                {
                    /* do nothing, cuz ur ok */
                }
            }
            if (vals.empty())
            {
                break;
            }
        }
        for (auto e : vals)
        {
            ma[e] = n - 1;
        }
        for (auto e : a)
        {
            cout << ma[e] << " ";
        }
        cout << endl;
    }
}