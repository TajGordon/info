#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf LONG_LONG_MAX
#define pb push_back

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> P(n);
    map<int, int> cont;
    map<int, int> first;
    map<int, int> last;
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
            last[P[i]] = i;
        }
    }

    int base_count = 0;
    map<int,int> ind;
    vector<int> keys;
    for (int i = 0; i < n; i++)
    {
        if (cont[P[i]] == 1)
        {
            last[P[i]] = first[P[i]];
            keys.pb(P[i]);
            ind[keys.size()-1] = i;
        }
        else if (i == first[P[i]] || i == last[P[i]])
        {
            keys.pb(P[i]);
            ind[keys.size()-1] = i;
        }
        else
        {
            base_count++;
        }
    }
    int m = keys.size();
    int min_cnt = n-1;
    cout << base_count << endl;
    cout << min_cnt << endl;

    for (auto e : keys)
    {
        cout << e << " ";
    }
    cout << endl;


    for (int i = 0; i < m; i++)
    {
        int offset = 1;
        int x = keys[i];
        int ones_staying = 1;
        /* manually check first one */
        cout << x << " is being checked" << endl;
        cout << ind[x] << " is ind[x] for " << x << endl;
        if (cont[x-1] < 2 || (first[x-1] > ind[i] || last[x-1] < ind[i]))
        {
            continue;
        }
        cout << x << " did not get stuck" << endl;
        while (offset < x)
        {
            if (cont[x-offset-1] < 2 
                || (first[x-offset-1] > first[x-offset] 
                || last[x-offset-1] < last[x-offset]))
            {
                break;
            }
            else
            {
                offset++;
                ones_staying += 2;
            }
        }
        cout << "for " << x << " there are " << ones_staying << " staying" << endl;
        if (m - ones_staying + base_count < min_cnt) min_cnt = m - ones_staying + base_count;
    }

    cout << min_cnt << endl;
    
    return 0;
}
