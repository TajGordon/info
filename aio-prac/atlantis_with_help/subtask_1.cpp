#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LONG_LONG_MAX
signed main()
{
    int n, l; cin >> n >> l;
    vector<int> B(n);
    vector<int> R(n); /* will always be 1 for this subtask */
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
        cin >> R[i];
    }
    int t; cin >> t;
    vector<int> X(t);
    vector<int> S(t);
    for (int i = 0; i < t; i++)
    {
        cin >> X[i];
        cin >> S[i];
    }
    /* precompute the nearest old bridges */
    vector<int> nearest_old_bridge(t);
    vector<int> min_cost_with_nearest_old_bridge(t, inf);
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(X[i] - B[j]) <= min_cost_with_nearest_old_bridge[i])
            {
                nearest_old_bridge[i] = B[j];
                min_cost_with_nearest_old_bridge[i] = abs(X[i] - B[j]);
            }
        }
    }
    /* brute force now */
    vector<int> min_cost_if_bridge_here(l, inf);
    int best_index_for_bridge = 0;
    int lowest_sum_for_new_bridge = inf;
    for (int i = 0; i < l; i++)
    {
        /* don't add a bridge where one already is */
        if (find(B.begin(), B.end(), i) != B.end()) continue;
        min_cost_if_bridge_here[i] = 0;
        for (int j = 0; j < t; j++)
        {
            if (abs(X[j] - i) <= min_cost_with_nearest_old_bridge[j])
            {
                min_cost_if_bridge_here[i] += 2 * abs(X[j] - i) + 1;
            }
            else
            {
                min_cost_if_bridge_here[i] += 2 * min_cost_with_nearest_old_bridge[j] + 1;
            }
        }
        if (min_cost_if_bridge_here[i] < lowest_sum_for_new_bridge)
        {
            lowest_sum_for_new_bridge = min_cost_if_bridge_here[i];
            best_index_for_bridge = i;
        }
    }
    cout << lowest_sum_for_new_bridge << endl;
}
