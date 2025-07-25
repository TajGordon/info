#include <bits/stdc++.h>
using namespace std;    
int main()
{
    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        int n, k;
        cin >> n >> k;
        int total = 0;
        int maxx = 0;
        for (int i = 0; i < k; i++)
        {
            int ai;
            cin >> ai;
            if (ai > maxx)
            {
                if (maxx > 0) total += (2 * maxx - 1);
                maxx = ai;
            }
            else
            {
                total += (2 * ai - 1);
            }
        }
        cout << total << endl;
    }
}