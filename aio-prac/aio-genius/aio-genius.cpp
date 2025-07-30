#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int n,p;
    cin >> n >> p;

    int rounds = 0;
    int sum = 0;
    while (sum + rounds + 1 <= p)
    {
        sum += ++rounds; /* if this doesn't work, needs brackets */
    }

    int extra_points = p - sum; /* will be 0 when p = sum, no dangling problems! */
    int extra_rounds = rounds - n*floor(rounds/n);

    int last_person = (rounds % n == 0)?n:rounds % n + 1;
    int second_last_person = (last_person == 1)?n:last_person-1;

    /* (rounds / n) = how many everyone has done, 
    rounds - n*floor(rounds/n) = how many extra rounds there are (explicit flooring since compiler might try to optimize) 
    if (second_last_person <= rounds - n*floor(rounds/n)) add one */
    int rounds_second_last_person_did = rounds / n + (second_last_person <= extra_rounds);
 
    /* if p == sum: then the last person had a full round, and will have the most points */
    if (!extra_points) 
    {
        cout << "The last person won! (" << last_person << "th)" << endl;
    }

    /* now we have checked if the last person won be default, */
    /* and have the id of the last and second to last people */
    /* can either figure out how many problems each solved */
    /* and compare the amounts */
    /* or do that fun thing with the distance */
    /* and only count how many problems the winner solved */
    int distance = rounds_second_last_person_did * (n-1); /* not expanding this time for no reason :p */
    int points = 0; /* yes the point calculations and methods chosen is kinda weird.. */
    if (extra_points > distance)
    {
        points = (floor(rounds / n)/2) * (2 * last_person + (floor(rounds / n) - 1) * n) + extra_points;
        // cout << "The last person won! (" << last_person << ") with " << points << " points!" << endl;
        cout << last_person << " " << points << endl;
    }
    else
    {
        points = (rounds_second_last_person_did / 2) * (2 * second_last_person + (rounds_second_last_person_did - 1) * n);
        // cout << "The second to last person won! (" << second_last_person << ") with " << points << " points!" << endl;
        cout << second_last_person << " " << points << endl;
    }
}




















// int main()
// {
//     // n = num people
//     // p = prob count
//     int n, p;
//     cin >> n >> p;
//     cout << " have not yet figured out how many points people have" << endl;
//     // assuming the amoutn of problems is enough for the last person to solve a complete set with no remainder
//     // a = i + (r-1) * p?
//     // num problems solved by person i = i + (r-1) * p
//     // num problems solved at any index, assuming full rounds, is 1+2+3+4+5...+n
//     // sum formula until it exceeds p
//     // get round count
//     // every round that someone has a ful set, they become 1 more ahead of the perso nbehind them
//     // so the last person to get a full set with be num_rounds_passed ahead of the person behind them, 
//     // so will the person behind the last person, and so on, until our current person
//     // so the difference from the last full roudn person, and the last person, 
//     // is num_rounds * num_people
//     // so get total_rounds run, and the number of cycles
//     // find the last person
//     // if theres some remainder, find out how much
//     // if remainder > num_cycles * num_people: last_person
//     // else: second_last_person
//     // int num_rounds = 0;
//     // /* there is probably a formula for this */
//     // int sum = 0;
//     // while (sum + num_rounds + 1 <= p) {
//     //     sum += (++num_rounds);
//     // }
//     // int num_cycles = num_rounds / n; /* automatically does a floor */
//     // /* the last person is the number of extra rounds */
//     // int last_person = num_rounds - num_cycles * n;
//     // if (last_person == 0)
//     // {
//     //     // winner = n
//     //     // NEED HOW MUCH THEY SOLVED
//     //     cout << n << " NOT FILLED IN THE AMOUTN OF SOLVED BY THIS PERSON" << endl;
//     //     return 0;
//     // }
//     // int second_last_person = last_person - 1;
//     // if (second_last_person == 0) second_last_person = n;
//     // int slp_ahead = num_cycles * (n-1);
//     // if (last_person > 1) slp_ahead += (n-1);
//     // int extra_points = p - sum;

//     // if (extra_points > slp_ahead) 
//     // {
//     //     cout << last_person << " won (lastperson)" << endl;
//     // }
//     // else
//     // {
//     //     cout << second_last_person << " won (second_lastPerson)" << endl;
//     // }
// }

