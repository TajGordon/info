#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q; cin >> q;
    queue<int> qu;
    while (q--)
    {
        int o; cin >> o;
        if (o == 1)
        {
            int x; cin >> x;
            qu.push(x);
        }
        else
        {
            cout << qu.front() << endl;
            qu.pop();
        }
    }
}