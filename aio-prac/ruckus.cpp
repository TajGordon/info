#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, l, k, m; cin >> n >> l >> k >> m;
    map<int, int> left_holding;
    map<int, int> right_holding;
    for (int i = 0; i < l; i++)
    {
        int x, y; cin >> x >> y;
        left_holding[x] = y;
        right_holding[y] = x;
    }
    vector<vector<int>> groups;
    set<int> used;
    for (int i = 1; i <= n; i++)
    {
        if (used.count(i)) continue;
        vector<int> group;
        stack<int> stacky;
        stacky.push(i);
        while (!stacky.empty())
        {
            if (used.count(stacky.top())) 
            {
                stacky.pop();
                continue;
            }
            used.insert(stacky.top());
            group.push_back(stacky.top());
            if (left_holding[stacky.top()] != 0) 
            {
                stacky.push(left_holding[stacky.top()]);
            }
            if (right_holding[stacky.top()] != 0) 
            {
                stacky.push(right_holding[stacky.top()]);
            }
            stacky.pop();
        }
        if (!group.empty()) groups.push_back(group);
    }
    // for (auto g : groups)
    // {
    //     for (auto e : g)
    //     {
    //         cout << e << " ";
    //     }
    //     cout << endl;
    // }
    /* premade groups + freestanders */
    /* take premade groups, if size - m >= m, remove one from it (or make more using more lolipops), */
    /* make groups of freeloaders of size m */
    /* if any left over, and there are groups with excess people, use lolipops to free them and use in another group */

    /* subtask 1 & 2: k = 0, m = 1 */
    int cnt = 0;
    for (auto g : groups)
    {
        if (groups.size() >= m) cnt++;
    }
    cout << cnt << endl;
}
