#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> p(n);
        vector<int> a;
        int b = 0;
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            a.push_back(x);
            if (x == 1)
            {
                p[i] = b;
                while (find(p.begin(), p.end(), (b)) != p.end()) { b++; };
                continue;
            }
            if (find(p.begin(), p.end(), b - x) != p.end() || b - x < 0)
            {
                p[i] = b;
                while (find(p.begin(), p.end(), (b)) != p.end()) { b++; };
            }
            p[i] = b - x;
        }
        for (auto e : p)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}
