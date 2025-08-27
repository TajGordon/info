#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf LONG_LONG_MAX
#define pb push_back

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n);
    int mi = 0;
    int ch = 0;
    int cl = 0;
    for (int i =0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] == ch)
        {
            cl++;
            if (cl * ch > mi)
            {
                mi = cl * ch;
            }
        }
        else
        {
            ch = A[i];
            cl = 1;
            if (ch > mi)
            {
                mi = ch;
            }
        }
    }
    
    cout << mi << endl;
    
    return 0;
}
