#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s; cin >> s;

        while (true)
        {
            vector<char> v;
            for (auto c : s)
            {
                v.push_back(c);
                if (v.size() >= 3)
                {
                    if (v[v.size() - 1] == 'B' &&
                        v[v.size() - 2] == 'B' &&
                        v[v.size() - 3] == 'A'
                    ) 
                    {
                        v.pop_back();
                        v.pop_back();
                        v.pop_back();
                        v.push_back('B');
                        v.push_back('A');
                    }
                }
            }

            string ss = "";
            for (auto c : v) ss += c;
            if (ss == s) 
            {
                cout << ss << '\n'; break;
            }
            else s = ss;
        }
    }
}