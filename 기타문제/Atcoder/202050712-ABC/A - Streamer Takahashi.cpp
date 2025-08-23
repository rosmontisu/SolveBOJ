#include <iostream>
using namespace std;

int main()
{
  int t, st, ed; cin >> t >> st >> ed;
  int cnt = 0;
  while (t--)
  {
    int a, b; cin >> a >> b;
    if (a <= st && b >= ed) cnt++;
  }
  cout << cnt;
}