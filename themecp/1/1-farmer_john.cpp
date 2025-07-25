#include <bits/stdc++.h>
using namespace std;    
int main()
{
    int t;
    cin >> t;
    ios::sync_with_stdio();
    for (int T = 0; T < t; T++)
    {
        int n,k;
        cin >> n >> k;
        if (n == k)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "1 ";
            }
        }
        else if (k == 1)
        {
            for (int i = 1; i < n; i++)
            {
                cout << "1 ";
            }
            cout << '2';
        }
        else
        {
            cout << "-1";
        }
        cout << endl;
    }
}