#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int pc = 0;
        int nc = 0;
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            if (x == -1)
            {
                nc++;
            }
            else
            {
                pc++;
            }
        }
        int t = 0;
        int f = max(0, nc - pc) / 2;
        while (nc - f > pc + f) f++; /* should only run once */
        if ((nc - f) & 1) t++;
        t += f;
        cout << t << endl;
    }
}