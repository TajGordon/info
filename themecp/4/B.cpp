#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        string ops = "1"; /* append 1 if we added, 0 if we didnt */
        int f;
        cin >> f;
        int p = f;
        bool s = false;
        q--;
        while (q--)
        {
            int x; cin >> x;
            if (s)
            {
                if (x >= p && x <= f)
                {
                    ops.append("1");
                    p = x;
                }
                else
                {
                    ops.append("0");
                }
            }
            else
            {
                if (x >= p)
                {
                    ops.append("1");
                    p = x;
                }
                else
                {
                    if (x <= f)
                    {
                        ops.append("1");
                        s = true;
                        p = x;
                    }
                    else
                    {
                        ops.append("0");
                    }
                }
            }
        }
        cout << ops << endl;
    }
}