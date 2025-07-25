#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int sy = y / 2;
        int b = 0;
        if (y & 1) {b++;sy++;}
        int sx = (sy * 7 + 4 * b >= x)?0:((x - sy * 7 - 4 * b)/15);
        sx += (x - 7*sy - 4*b > sx * 15);
        cout << sy + max(sx,0) << endl;
    }
}