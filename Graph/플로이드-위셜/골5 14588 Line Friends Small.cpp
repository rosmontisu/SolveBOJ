#include <iostream>
#include <vector>
using namespace std;

int map[252][252];
const int INF = 0x3f3f3f3f;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    





    for (int i = 1; i <= m; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;

        map[u][v] = 0; // 일방통행 
        map[v][u] = 1;
        if (b == 1)
            map[v][u] = 0; // 양방향
    }

    // 플로이드로 일방+양방 모두 사용할때의 최단 거리를 기록
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    int k; // 질문수
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << map[s][e] << '\n';
    }
}