

/* this is just a brute-force solution because the other isn't working */
/* will we have enough time? probably not. */
/* it's a 0.05 sec time limit, roughly 0% chance this is quick enough, */
/* especially when I have an alternative algorithm that almost works */
/* what in the actual fuck, i won a lottery! */
/* (i wish this lottery gave me some money...) */
/* we aren't TLE-ing, but getting a single wrong answer??? */
/* ITS TIME TO EDGE! */
/* (edge cases checking) */
#include <bits/stdc++.h>

using namespace std;
int main(void)
{
    int n,p;
    cin >> n >> p;

    vector<int> points(n + 1,0);
    int person = 1;
    int total_points = 0;
    int round = 0;
    while (total_points + round + 1 <= p)
    {
        total_points += (++round);
        if (person > n) person = 1;
        points[person++] += round;
    }
    if (person > n) person = 1;
    points[person] += (p - total_points);

    int max_points = 0;
    int genius = 1; /* this needs to start at 1, not 0 */
    for (int i = 1; i <= n; i++)
    {
        if (points[i] > max_points) 
        {
            max_points = points[i];
            genius = i;
        }
    }
    cout << genius << " "<< max_points << endl;
}