#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q; cin >> n >> q;
    vector<int> boxes(n);
    vector<int> putin(q);
    int k = 0;
    while (q--)
    {
        int xi; cin >> xi;
        if (xi == 0)
        {
            int mini = INT_MAX;
            int idx = 0;
            for (int i = 0; i < n; i++)
            {
                if (boxes[i] < mini) 
                {
                    mini = boxes[i];
                    idx = i;
                }
            }
            boxes[idx]++;
            putin[k++] = idx;
        }
        else if (xi >= 1)
        {
            boxes[xi-1]++;
            putin[k++] = xi-1;
        }
    }
    for (auto e : putin)
    {
        cout << e + 1 << " ";
    }
    cout << endl;
}