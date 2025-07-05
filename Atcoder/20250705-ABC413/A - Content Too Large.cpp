#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int sum = 0;
  while(n--)
  {
    int a;
    cin >> a;
    sum += a;
    if (sum > m)
    {
      cout << "No";
      return 0;
    }
  }
  
  cout << "Yes";
  return 0;
}