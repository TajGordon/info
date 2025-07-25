#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    int cnt = 0;
    for (auto e : a)
    {
        if (k <= e) cnt++;
    }
    cout << cnt << endl;
}