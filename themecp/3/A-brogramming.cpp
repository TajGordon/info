#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = "";
        auto is_done = [](string s, string t) {
            for (auto c : s) 
            {
                if (c == '1') return false;
            }
            for (auto c : t) 
            {
                if (c == '0') return false;
            }
            return true;
        };
        int counter = 0;
        while (!is_done(s, t))
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                {
                    string tem = s.substr(i, s.size()-i);
                    s = s.substr(0,i);
                    t.append(tem);
                    counter++;
                    break;
                }
            }
            for (int i = 0; i < t.size(); i++)
            {
                if (t[i] == '0')
                {
                    string tem = t.substr(i, t.size()-i);
                    t = t.substr(0,i);
                    s.append(tem);
                    counter++;
                    break;
                }
            }
        }
        cout << counter << endl;
    }
}