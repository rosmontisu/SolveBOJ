// 무식하게 부르트 포스로 풀엇 (n * m = 40000)

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 입력력
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];

    // 누적합
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] + v[i][j] - s[i - 1][j - 1];

    // 구간합
    int ans = -10000 * n * m -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int x = 1; x <= i; x++)
                for (int y = 1; y <= j; y++)
                    ans = max(ans, s[i][j] - s[x-1][j] - s[i][y-1] + s[x-1][y-1]);

    cout << ans;

    return 0;
}