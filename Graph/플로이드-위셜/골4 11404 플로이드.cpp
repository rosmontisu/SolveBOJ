#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000*101; // 존재하지 않는 경로 edge는 inf로 설정
int map[102][102]; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n; // 도시 수 - node
    cin >> m; // 버스 수 - edge

    // 그래프 초기화
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            map[i][j] = INF;
    }

    // 그래프 입력 
    for (int i = 0; i < m; i++)
    {
        int a, b, c; // a에서 b로 가는 비용 c
        cin >> a >> b >> c;

        map[a-1][b-1] = min(map[a-1][b-1], c); // 최소 비용 검사, 다음부터는 인덱스 1부터 쓰도록 개선
    }

    // 플로이드 시작
    for (int i = 0; i < n; i++) // 0번부터 전부 경유할것
    {
        for (int j = 0; j < n; j++) // 출발지에서
        {
            for (int k = 0; k < n; k++) // 모든 도착지를 검사
            {
                if (j == k) // 출발지와 도착지가 같다면 패스
                    continue;
                // 경유 비용과 직통 비용을 비교
                // map[j][i] + map[i][k] = 경유 비용
                // map[j][k] = 직통 비용
                if (map[j][i] + map[i][k] < map[j][k])
                    map[j][k] = map[j][i] + map[i][k];
            }
        }
    }

    // i에서 j로 가는 최소비용 출력 (모든도시)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}