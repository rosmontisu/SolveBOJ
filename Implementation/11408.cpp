#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

vector<pair<int, int>> v[4002];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int jobs;
        cin >> jobs;
        for (int j = 0; j < jobs; j++)
        {
            int a, b;
            cin >> a >> b;
            v[i].push_back({a, b});
        }
        for (auto i : v[i-1])
            cout << i.first << i.second;
        cout << '\n';
    }
}