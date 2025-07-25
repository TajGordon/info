#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int k, n; cin >> k >> n;
        int prev = 1;
        int cnt = 1;
        cout << prev << " ";
        for (int i = 1; i < k; i++)
        {
            if (prev + i + (k-cnt-1) > n) break;
            prev += i;
            cout << prev << " ";
            cnt++;
        }
        k -= cnt;
        while (k--)
        {
            cout << (++prev) << " ";
        }
        cout << endl;
    }
}