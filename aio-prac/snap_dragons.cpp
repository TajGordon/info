#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, s; cin >> r >> s;
    array<int, 10002> R = {};
    array<int, 10002> S = {};
    int mr = 0;
    int ms = 0;
    while (r--)
    {
        int x; cin >> x;
        R[x]++;
        if (x > mr) mr = x;
    }
    while (s--)
    {
        int x; cin >> x;
        S[x]++;
        if (x > ms) ms = x;
    }
    long long t = 0;
    for (int i = 0; i <= min(ms, mr); i++)
    {
        t += (R[i] * S[i]);
    }
    cout << t << endl;
}