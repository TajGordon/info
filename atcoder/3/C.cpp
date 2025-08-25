#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> m(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        b[i] = x;
        if (x < m[i]) m[i] = x;
        s += m[i];
    }
    while (q--)
    {
        char c; cin >> c;
        int x, v; cin >> x >> v;
        if (c == 'A')
        {
            a[x-1] = v;
        }
        else
        {
            b[x-1] = v;
        }
        int diff = m[x-1] - min(a[x-1], b[x-1]);
        m[x-1] = min(a[x-1], b[x-1]);
        s -= diff;
        cout << s << endl;
    }
}