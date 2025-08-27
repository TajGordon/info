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
    vector<int> U(n);
    int min_ugliness_base = 0;
    int min_ugliness = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
        if (n > 0)
        {
            U[i] += abs(H[(i)] - H[(i-1)]);
            U[i-1] += abs(H[(i)] - H[(i-1)]);
            min_ugliness_base += U[i-1];
        }
    }
    min_ugliness_base += U[n-1];

    /* do first and last ones later */
    for (int i = 1; i < n-2; i++)
    {
        int tmp = min_ugliness_base - U[i];
        int avg = (H[i-1] + H[i+1]) / 2;
        tmp += abs(H[i-1] - avg) + abs(H[i+1] - avg);
        if (tmp < min_ugliness) min_ugliness = tmp;
        /* also try +1 since int division */
        tmp = min_ugliness_base - U[i];
        avg++;
        tmp += abs(H[i-1] - avg) + abs(H[i+1] - avg);
        if (tmp < min_ugliness) min_ugliness = tmp;
    }
    /* first and last ones */
    {
        int tmp = min_ugliness_base - U[0];
        if (tmp < min_ugliness) min_ugliness = tmp;
        tmp = min_ugliness_base - U[n-1];
        if (tmp < min_ugliness_base) min_ugliness = tmp;
    }
    
    cout << min_ugliness << endl;
    
    return 0;
}
