#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf LONG_LONG_MAX
#define pb push_back

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> p[i];
    }

    vector<int> left(100005, 0);
    vector<int> right(100005, 0);

    vector<int> l(n, 0);
    vector<int> r(n, 0);

    /* dp, longest on either side from each one */
    for (int i = 0; i < n; i++)
    {
        int x = p[i];
        left[x] = left[x-1] + 1;
        l[i] = left[x];
    }
    for (int i = n-1; i >= 0; i--)
    {
        int x = p[i];
        right[x] = right[x-1] + 1;
        r[i] = right[x];
    }
    

    int longest_sequence = 0;

    for (int i = 0; i < n; i++)
    {
        longest_sequence = max(longest_sequence, 2 * min(l[i], r[i]) - 1);
    }

    cout << n - longest_sequence << endl;
    
    return 0;
}
