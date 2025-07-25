#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
 
    vector<int> h(n);
    vector<int> s(m);
    vector<int> p(m);
 
    {
        for (int i = 0; i < n; i++)
        { 
            cin >> h[i]; 
        }
        for (int i = 0; i < m; i++)
        { 
            cin >> s[i]; 
        }
        for (int i = 0; i < m; i++)
        { 
            cin >> p[i]; 
        }
    }
 
    auto bad = [h, s, p](int house, int store) {
        return abs(h[house] - s[store]) + p[store];
    };
 
    vector<int> best(n);
    

    
}