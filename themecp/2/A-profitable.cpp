#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        int a,b;
        cin >> a >> b;
        int m = max(0,a - max(0, b-a));
        cout << m << endl;
    }
}