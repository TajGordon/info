#include <bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> v;
        int c = 0;
        int s = 0;
        int m = 0;
        for (int i = 0;i < n; i++)
        {
            int x; cin >> x;
            v.push_back(x);
            if (x > m) {m = x;}
            s += x;
            c += (s == 2 * m);
        }
        cout << c << endl;
    }
}