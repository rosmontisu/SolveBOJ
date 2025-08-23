#include <iostream>
#include <queue>
#include <utility>
using namespace std;

// pair로 쿼리를 넣어야될듯?
// k 상수가 너무 큼 10e9 -> 10억
int main()
{
  deque<pair<long long, long long>> q;
  long long t; cin >> t;
  while (t--)
  {
    long long n; cin >> n;
    if (n == 1)
    {
      long long a, b;
      cin >> a >> b;
      q.push_back({a, b});
    }
    else
    {
      long long k; cin >> k;
      long long sum = 0;
      // b가 a개 만큼 있음.
      while (k > 0)
      {
        auto cur = q.front(); q.pop_front();
        long long a = cur.first;
        long long b = cur.second;
        if (k >= a)
        {
          sum += a*b;
          k -= a;
        }
        else
        {
          sum += b*k;
          a -= k;
          k = 0;
          q.push_front({a, b});
        }
      }
      
      cout << sum << '\n';
    }
  }
}