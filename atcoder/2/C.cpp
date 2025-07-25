#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> arr(n+5);
    vector<int> buffer(n + 5);
    int t, p, x, k;
    int tok = 0;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> p >> x;
            int simidx = (tok + p) % n;
            if (simidx == 0) simidx = n;
            arr[simidx] = x;
        }
        else if (t == 2)
        {
            cin >> p;
            int simidx = (tok + p) % n;
            if (simidx == 0) simidx = n;
            if (arr[simidx] > 0)
                cout << arr[simidx] << endl;
            else cout << simidx << endl;
        }
        else if (t == 3)
        {
            cin >> k;
            tok += k;
            tok %= n;
        }
    }
}