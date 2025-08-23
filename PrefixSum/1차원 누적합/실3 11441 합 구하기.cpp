// 구간합구하기4랑 그냥 똑같네요

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        v[i] = v[i - 1] + a;
    }

    int m; cin >> m;
    while (m--)
    {
        int i, j; 
        cin >> i >> j;

        cout << v[j] - v[i - 1] << '\n';
    }

    return 0;
}