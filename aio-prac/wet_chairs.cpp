/***************************************************









does putting the same code in C++ make it accepted?







*****************************************************/

#include <bits/stdc++.h>
using namespace std;

bool cws(int c, int n, int k, string chairs, int size) {
    int p = 0;
    int nws = 0;
    for (int i = 0; i < size; i++) {
        nws += (chairs[i] == 'w');
    }

    if ((size - nws) >= (n - k)) return true;

    for (int i = 1; i < c - size + 1; i++)
    {
        p++;
        nws -= (chairs[p - 1] == 'w');
        nws += (chairs[p + size - 1] == 'w');
        if ((size - nws) >= (n - k)) return true;
    }
    return false;
};

int main(void)
{
    int c,n,k;
    cin >> c >> n >> k;
    string chairs;
    cin >> chairs;

    for (int i = n; i < c + 1; i++)
    {
        if (cws(c,n,k,chairs,i)) {
            cout << i << endl;
            break;
        }
    }
}
