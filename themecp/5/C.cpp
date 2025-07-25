#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        long long osum = 0;
        long long esum = 0;
        long long ecnt = 0;
        long long ocnt = 0;
        for (long long i = 0; i < n; i++)
        {
            long long x; cin >> x;
            if (i & 1)
            {
                osum += x;
                ocnt++;
            }
            else
            {
                esum += x;
                ecnt++;
            }
        }
        /* ecnt / ocnt should be some formula with n, but i cbf to figure that shit out */
        if ((osum / ocnt) != (esum / ecnt) || osum % ocnt != 0 || esum % ecnt != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}