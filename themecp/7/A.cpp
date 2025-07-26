#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n; /* ignoring cuz c++ so we just input string :) */
        bool p = false;
        string s; cin >> s;
        for (auto c : s)
        {
            if (c == '0')
            {
                p = true;
                break;
            }
        }
        if (p) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
