#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s; cin >> s; s = s.substr(0, 5);
    int n; cin >> n;
    int ans = 0;
    while (n--)
    {
        string ss; cin >> ss; ss = ss.substr(0, 5);
        if (s == ss) ans++;
    }
    cout << ans;
}