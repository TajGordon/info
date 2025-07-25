#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        /* starting cell = (1,1), grid [1,n] */
        if (((abs(n - sx) <= d && abs(1 - sx) <= d) || (abs(m - sy) <= d && abs(1 - sy) <= d)) || (abs(n-sx) + abs(m-sy) <= d)) cout << "-1" << endl;
        else
        {
            cout << (n-1) + (m-1) << endl;
        }
    }
}