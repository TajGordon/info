#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int ax, ay, ad; cin >> ax >> ay >> ad;
  int bx, by, bd; cin >> bx >> by >> bd;
  int dx = abs(ax-bx), dy = abs(ay-by);
  float d = sqrt(dx*dx + dy*dy);
  if(d > ad + bd 
      || (ad + d < bd)
      || (bd + d < ad))
  {
    cout << "no" << endl;
  }
  else
  {
    cout << "yes" << endl;
  }
}
