#include <vector>
#include <iostream>

using namespace std;

int Find(int a, vector<int>* parent) 
{
    if ((*parent)[a] != a)
    {
        /* saves memory space by not storing in intermediary variable (eg int p = ...), however now have an additional memory access to some random place, which is faster? idk */
        (*parent)[a] = Find((*parent)[a], parent);
        return (*parent)[a];
    }
    return a;
}

void Union(int a, int b, vector<int>* parent)
{
    (*parent)[Find(b, parent)] = (*parent)[Find(a, parent)];
}

int main()
{
    int n, q; cin >> n >> q;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    while (q--)
    {
        int t, u, v; cin >> t >> u >> v;
        if (t)
        {
            if (Find(u, &parent) == Find(v, &parent))
            { cout << '1' << endl; }
            else
            { cout << '0' << endl; }
        }
        else
        {
            Union(u, v, &parent);
        }
    }
}