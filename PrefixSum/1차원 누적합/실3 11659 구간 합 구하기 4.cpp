#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; 
    cin >> n >> m;

    vector<int> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int nn; cin >> nn;
        v[i] = v[i - 1] + nn;
    }

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        cout << v[j] - v[i - 1] << '\n';
    }

    return 0;
}