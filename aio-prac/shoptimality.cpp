#include <bits/stdc++.h>

using namespace std;

#define int long long

#define inf LONG_LONG_MAX

signed main()

{

    int n, m; cin >> n >> m;

    /* houses and stores are already sorted */

    vector<int> house(n);

    vector<int> store(m);

    vector<int> price(m);

    for (int i = 0; i < n; i++)

    {

        cin >> house[i];

    }

    for (int i = 0; i < m; i++)

    {

        cin >> store[i];

    }

    for (int i = 0; i < m; i++)

    {

        cin >> price[i];

    }

 

    /* feels like dp */

    vector<int> badness(n, inf);

    vector<int> best_store(n);

    /* start search from the best for the previous house, and then continue right */

    /* limiting factors: distance and current best, if distance total > current_best break, distance - lowest price, something where price factors into max distance, maybe segment the min_price in an area using another dp, else keep searching */

    /* solve the first one manually */

    {

        for (int i = 0; i < m; i++)

        {

            if (abs(store[i] - house[0]) + price[i] <= badness[0])

            {

                badness[0] = abs(store[i] - house[0]) + price[i];

                best_store[0] = i;

            }

        }

    }

    /* such nice subcases, telling us to remember the case when everything is to the right. idk if it will fail because of that, but such nice people they are... */

    for (int i = 1; i < n; i++)

    {

        best_store[i] = best_store[i-1];

        badness[i] = abs(store[best_store[i]] - house[i]) + price[best_store[i]];

        /* bounds check? */

        for (int j = best_store[i-1] + 1; j < m; j++)

        {

            /* min dist check with min price here for optimisation if needed */

            /* if it literally can't be any better */

            if (abs(store[j] - house[i]) > badness[i]) break;

 

            /* if equivalent, use the further one because more likely to be best for next house */

            if (abs(store[j] - house[i]) + price[j] <= badness[i])

            {

                badness[i] = abs(store[j] - house[i]) + price[j];

            }

        }

    }

    for (int i = 0; i < n; i++)

    {

        cout << badness[i] << " ";

    }

    cout << endl;

}