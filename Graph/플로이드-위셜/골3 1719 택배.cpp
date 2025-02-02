#include <iostream>
#include <vector>
using namespace std;

int map[252][252];
const int INF = 0x3f3f3f3f;

int ans[252][252];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m; // 집하장, 경로
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = INF;
            if (i == j) map[i][j] == 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        map[a][b] = c;
        map[b][a] = c;

        // 초기 최단경로는 직통
        ans[a][b] = b;
        ans[b][a] = a;
    }

    // 플로이드
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (map[i][k] + map[k][j] < map[i][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    ans[i][j] = ans[i][k]; // 최단경로 시작점은 i->k
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) cout << '-' << ' ';
            else cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}