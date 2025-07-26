#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int c = 0;
        int r = 0;
        int p = -2;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            if (p + 1 >= c)
            { r++; }
            else { p = c; }
        }
        cout << n - r << endl;
    }
}
