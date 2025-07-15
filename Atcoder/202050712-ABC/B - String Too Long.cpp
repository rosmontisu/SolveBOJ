#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
  int t; cin >> t;
  queue<char> q;
  int cnt = 0;
  while (t--)
  {
    char c; int n; cin >> c >> n;
    cnt += n;
    if (cnt > 100)
    {
      cout << "Too Long";
      return 0;
    }
    while (n--) q.push(c);
  }
  
  while (cnt--)
  {
    cout << q.front(); q.pop();
  }
}