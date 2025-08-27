#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf LONG_LONG_MAX
#define pb push_back

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* min to max diff = len / 2 (int div so floor) */
    int n; cin >> n;
    vector<int> P(n);
    map<int, int> cont;
    map<int, int> first;
    map<int, int> last;
    map<int, vector<int>> middles;
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
        cont[P[i]]++;
        if (cont[P[i]] == 1)
        {
            first[P[i]] = i;
        }
        else
        {
            middles[P[i]].pb(last[P[i]]);
            last[P[i]] = i;
        }
    }

    int cnt = 0; /* base line to add to everything */
    /* reduce by counting, if num(x) != 2, remove all internal xs */
    vector<int> one_conts;
    vector<int> new_keys;
    for (int i = 0; i < n; i++)
    {
        if (cont[P[i]] > 1 && (i == first[P[i]] || i == last[P[i]]))
        {
            new_keys.pb(P[i]);
        }
        else if (cont[P[i]] == 1)
        {
            if (cont[P[i]-1] == 0 || 
                ((cont[P[i]-1] > 1) && (first[P[i]-1] < first[P[i]]) && (last[P[i-1]] > last[P[i]])))
            {
                new_keys.pb(P[i]);
                one_conts.pb(P[i]);
                last[P[i]] = first[P[i]];
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            cnt++;
        }
    }
    n = new_keys.size();

    // for (auto e : new_keys)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;

    /* new filtered list */
    int min_cnt = n - 1; /* always an option to remove every element but one */

    for (auto x : one_conts)
    {
        int ones_staying = 1;
        int offset = 0;
        while (offset < x) /* random bound, shouldn't be hit probably */
        {
            if (cont[x-offset-1] <= 1)
            {
                break;
            }
            else
            {
                if (first[x-offset-1] > first[x-offset] || last[x-offset-1] < last[x-offset])
                {
                    break;
                }
                else
                {
                    offset++;
                    ones_staying += 2;
                }
            }
        }
        if (n - ones_staying < min_cnt) min_cnt = n - ones_staying;
    }

    cout << min_cnt + cnt << endl;
    
    return 0;
}
