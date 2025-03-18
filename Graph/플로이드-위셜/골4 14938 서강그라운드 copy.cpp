#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int INF = 0x3f3f3f3f;
int map[102][102];
int item[102];
int answer = 0;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    // 그래프 사용전 초기화
    for (int i = 1; i < 102; i++)
        for (int j = 1; j < 102; j++)
            map[i][j] = INF; // inf

    // 입력
    int n, m, r; // 도시 수, 수색 범위, 도로 수
    cin >> n >> m >> r;

    // 0. 도시에 방문하면 얻을 수 있는 아이템을 저장한다.
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        item[i] = t;
    }
    
    // 맵과 간선 비용 초기화
    for (int i = 1; i <= r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        map[a][b] = min(map[a][b], l);
        map[b][a] = min(map[b][a], l); // 양방향 간선
    }

    // 1. 플로이드로 최단거리를 구한다.
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) 
                    continue;
                if (map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }

    // 2. 수색범위 안에 있는 도시를 모두 방문한다.
    for (int i = 1; i <= n; i++)
    {
        int count = item[i]; // 2-1. 먼저 시작 도시의 아이템을 줍고
        for (int j = 1; j <= n; j++)
        {
            if (i == j) // 자기 자신은 제외
                continue;
            if (map[i][j] <= m) // 2-2. 수색 범위 안에서 아이템을 줍는다
                count += item[j];
        }

        // 3. 현재 시작 도시에서 얻은 아이템을 이전 최고값과 비교한다.
        answer = max(answer, count);

    }

    cout << answer;
}