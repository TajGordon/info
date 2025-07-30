#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> numbers(k + 1);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numbers[num]++;
    }
    for (int i = 1; i < k + 1; i++) {
        if (numbers[i] == 1) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}