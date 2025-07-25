#include <bits/stdc++.h>
using namespace std;
int main()
{
    array<int, 33> po = {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000};
    array<bool, 100020> ar = {false};
    for (int one = 32; one >= 0; one--)
    {
        ar[po[one]] = true;
        for (int two = 0; two < 33; two++)
        {
            if (po[one] * po[two] > 100000) continue;
            ar[po[one] * po[two]] = true;
            for (int three = 32; three >= 0; three--)
            {
                if (po[one] * po[two] * po[three] > 100000) continue;
                ar[po[one] * po[two] * po[three]] = true;
                for (int four = 0; four < 33; four++)
                {
                    if (po[four] * po[one] * po[two] * po[three] > 100000) continue;
                    ar[po[four] * po[one] * po[two] * po[three]] = true;
                }
            }
        }
    }
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        if (ar[n]) 
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}