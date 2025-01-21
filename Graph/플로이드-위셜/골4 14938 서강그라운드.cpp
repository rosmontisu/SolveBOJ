#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int item[102];
int map[102][102];
int nxt[102][102];

int answer = 0;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 1; i < 102; i++)
    {
        for (int j = 1; j < 102; j++)
        {
            map[i][j] = 0x3f3f3f3f; // inf
            nxt[i][j] = j;
        }
    }


    int n, m, r; // 도시 수, 수색 범위, 도로 수

    // 아이템 초기화
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
        map[a][b] = l;
    }

    // 플로이드로 경로 최소값을 먼저 구하고
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (map[i][k] + map[k][j] < map[i][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    // 아이템을 최단 경로로 수집
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int sum = 0;
            if (i == j)
                continue;
            int cur = i; // 현재 위치
            while (cur != j) // 도착지가 아니라면 계속 루프
            {
                sum += item[cur];
                if (sum > m) // 수색범위 넘어서면 여기서 중단
                    break;
                cur = nxt[cur][j]; // 커서가 현재 위치이므로 출발지
            }

            answer = max(answer, sum);
        }

    }

    cout << answer;
    
}