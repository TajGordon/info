#include <bits/stdc++.h>
using namespace std;
int main()
{
    int d, t; cin >> d >> t;
    array<int, 100010> val = {0};
    array<int, 100010> mival = {0};
    int ma = 0;
    while (t--)
    {
        int x, y; cin >> x >> y;
        val[x]--;
        val[y]++;
        if (x > ma) ma = x;
        if (y > ma) ma = y;
        if (val[x] < mival[x]) mival[x] = val[x];
    }
    int needed = 0;
    for (int i = 0; i <= ma; i++)
    {
        needed += -1 * mival[i];
    }
    cout << needed << endl;
}