#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf LONG_LONG_MAX
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, f; cin >> n >> f;
    vector<int> c(n);
    int min_found = inf;
    int min_idx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        if (c[i] < min_found)
        {
            min_found = c[i];
            min_idx = i;
        }
    }

    vector<pair<int,int>> left_side_tmp;
    vector<pair<int,int>> right_side_tmp;
    vector<pair<int,int>> left_side;
    deque<pair<int,int>> right_side;
    for (int i = 0; i < min_idx; i++)
    {
        left_side_tmp.push_back({c[i], i});
    }
    for (int i = min_idx; i < n; i++)
    {
        right_side_tmp.push_back({c[i], i});
    }
    if (left_side_tmp.size() > 0)
    {
        left_side.push_back(left_side_tmp.front());
        for (int i = 1; i < left_side_tmp.size(); i++)
        {
            if (left_side_tmp[i].first <= left_side.back().first)
            {
                left_side.push_back(left_side_tmp[i]);
            }
        }
    }
    if (right_side_tmp.size() > 0)
    {
        right_side.push_back(right_side_tmp.back());
        for (int i = right_side_tmp.size() - 2; i >= 0; i--)
        {
            if (right_side_tmp[i].first <= right_side.front().first)
            {
                right_side.push_front(right_side_tmp[i]);
            }
        }
    }

    // for (auto e : left_side)
    // {
    //     cout << e.first << ", " << e.second << " ";
    // }
    // cout << endl;

    int most_samples = -1;
    
    int most_right = right_side.size()-1;
    {
        int k = 0;
        for (int b = (most_right + 1)/2; b>=1; b/=2)
        {
            while (k + b <= most_right && right_side[0].first + right_side[k+b].first <= f) k+=b;
        }
        if (k > 0 && right_side[k].first + right_side[0].first <= f && right_side[k].second - right_side[0].second + 1 > most_samples)
        {
            most_samples = right_side[k].second - right_side[0].second + 1;
            most_right = k;
        }
    }
    // for (int i = 1; i < right_side.size(); i++)
    // {
    //     if (min_found + right_side[i].first > f) break;
    //     if (right_side[i].second - right_side[0].second + 1 > most_samples)
    //     {
    //         most_samples = right_side[i].second - right_side[0].second + 1;
    //         if (i > most_right) most_right = i;
    //     }
    // }
    for (int i = left_side.size() - 1; i >= 0; i--)
    {
        int k = 0;
        for (int b = (most_right + 1)/2; b >= 1; b /= 2)
        {
            while (k + b <= most_right && left_side[i].first + right_side[k+b].first <= f) k+=b;
        }
        if (right_side[k].first + left_side[i].first > f) break;
        if (right_side[k].second - left_side[i].second + 1 > most_samples)
        {
            most_samples = right_side[k].second - left_side[i].second + 1;
            most_right = k;
        }
    }

    cout << most_samples << endl;
}