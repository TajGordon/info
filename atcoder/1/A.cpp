#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    string a = "";
    for (auto c : s)
    {
        if (isupper(c)) a += c;
    }
    cout << a << endl;
}