#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf LONG_LONG_MAX
#define pb push_back

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string v; cin >> v;
    int ac=0, bc=0, cc = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 'A') ac++;
        if (v[i] == 'B') bc++;
        if (v[i] == 'C') cc++;
    }
    int m = max(ac,max(bc,cc));
    if ((ac == bc && ac == m) || (ac == cc) && (ac == m) || (bc == cc) && (bc == m))
    {
        cout << "T" << endl;
    }
    else
    {
        if (ac == m)
        {
            cout << "A" << endl;
        }
        else if (bc == m)
        {
            cout << "B" << endl;
        }
        else
        {
            cout << "C" << endl;
        }

    }

    return 0;
}
