#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int n, m; cin >> n >> m;
    int total_score = 0;
    vector<string> votes(n);
    vector<int> score(n);
    for (int i = 0; i < n; i++)
    {
        cin >> votes[i];
    }
    for (int r = 0; r < m; r++)
    {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (votes[i][r] == '0') x++;
            else y++;
        }
        if (!x||!y) total_score++;
        else
        {
            if (x < y)
            {
                for (int i = 0; i < n; i++)
                {
                    if (votes[i][r] == '0') score[i]++;
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (votes[i][r] == '1') score[i]++;
                }
            }
        }
    }
    int max_score = 0;
    vector<int> max_peoples;
    for (int i = 0; i < n; i++)
    {
        if (score[i] > max_score)
        {
            max_score = score[i];
            max_peoples.clear();
            max_peoples.push_back(i+1);
        }
        else if (score[i] == max_score)
        {
            max_peoples.push_back(i+1);
        }
    }
    for (auto e : max_peoples)
    {
        cout << e << " ";
    }
    cout << endl;
}