#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t; cin >> t;
    while (t--)
    {
        long long n; cin >> n;
        vector<long long> v;
        long long m = 0;
        for (long long i = 0; i < n; i++)
        {
            long long x; cin >> x;
            if (x > m) m = x;
            if (x < m) v.push_back(m - x);
        }

        if (v.empty())
        {
            cout << 0 << endl;
            continue;
        }
        long long y = 0;
        long long s = 0;
        for (auto e : v)
        {
            s += e;
            if (e > y) y = e;
        }
        cout << y + s << endl;
    }
}
