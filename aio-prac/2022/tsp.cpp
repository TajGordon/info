#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf LONG_LONG_MAX
#define pb push_back

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> L(n);
    vector<int> R(n);
    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> R[i];
    }
    int most = 0;
    for (int i = 0; i < n; i++)
    {
        if (L[i] >= most) most = L[i];
        else if (R[i] >= most) continue;
        else { cout << "NO" << endl; return 0; }
    }
    cout << "YES" << endl;
    
    return 0;
}
