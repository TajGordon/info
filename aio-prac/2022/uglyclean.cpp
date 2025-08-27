#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf LONG_LONG_MAX
#define pb push_back

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> H(n);
    vector<int> U(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
    }
    int base_uglyness = 0;

    for (int i = 1; i < n;i++)
    {
        U[i] = abs(H[i] - H[i-1]);
        base_uglyness += U[i];
        U[i-1] += U[i];
    }
    
    int min_uglyness = base_uglyness;

    for (int i = 0; i < n; i++)
    {
        int tmp = base_uglyness - U[i];
        if (i > 0 && i < n-1)
        {
            tmp += abs(H[i-1] - H[i+1]);
        }
        if (tmp < min_uglyness) min_uglyness = tmp;
    }

    cout << min_uglyness << endl;
    
    return 0;
}
