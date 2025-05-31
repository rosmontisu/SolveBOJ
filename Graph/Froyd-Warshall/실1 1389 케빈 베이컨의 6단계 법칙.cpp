#include <iostream>
#include <algorithm>
using namespace std;

int map[5005][5005];

const int INF = 987654321;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(&map[0][0], &map[5005][5005], INF);

    int n, m;
    cin >> n >> m;

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    // 각 노드에서 가장 먼 노드까지의 거리를 저장하면 되는 문제
        // 노드 하나하나 BFS 돌리거나
        // 플로이드로 전부 기록한 맵을 만들거나
            // - 연결 안된 정점은 어차피 INF니까?

    // 플로이드 
    for (int k = 1; k <= m; k++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                if (map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }
    

}