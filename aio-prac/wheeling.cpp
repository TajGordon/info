#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, m; cin >> n >> m;
    vector<int> V(n);
    vector<int> P(m);
    vector<int> votes(n);
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        V[i] = x-1;
        votes[V[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> P[i];
    }
    int total = 0;
    set<int> C = {0};
    vector<int> candidates;
    vector<int> free_voters;
    map<int, vector<int>> voters;
    for (int i = 1; i < n; i++)
    {
        if (votes[i] > votes[0]) { 
            C.insert(i);
            candidates.push_back(i);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (C.count(V[i]))
        {
            voters[V[i]].push_back(i);
        }
        else
        {
            free_voters.push_back(P[i]);
        }
    }
    /* sort biggest first */
    sort(free_voters.begin(), free_voters.end(), greater<int>());
    /* sort each of the voters to get cheapest ones first */
    for (auto c : C)
    {
        sort(voters[c].begin(), voters[c].end(), greater<int>());
    }
    sort(candidates.begin(), candidates.end(), [&voters](int a, int b) {
        return voters[a] > voters[b];
    });
    /* probably going to be fast enough */
    /* doesn't handle when multiple are tied for first */
    while (candidates.front() != 0)
    {
        if (free_voters.back() * 2 < voters[candidates.front()].back())
        {
            total += free_voters.back();
            free_voters.pop_back();
            votes[0]++;
        }
        else
        {
            total += voters[candidates.front()].back();
            voters[candidates.front()].pop_back();
            votes[0]++;
            votes[candidates.front()]--;
        }

        sort(candidates.begin(), candidates.end(), [&votes](int a, int b) {
            return votes[a] < votes[b];
        });
    }

    cout << total << endl;
}