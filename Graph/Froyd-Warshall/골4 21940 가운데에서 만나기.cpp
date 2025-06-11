#include <iostream>
#include <vector>
using namespace std;

int map[202][202];
vector<int> home;

const int INF = 0x3f3f3f3f;

int main()
{
    // map 초기화
    for (int i = 1; i < 202; i++)
        for (int j = 1; j < 202; j++)
            map[i][j] = INF;


    // 도시의 개수 n, 도로의 개수 m
    // A->B 시간 t

    // 총 인원 k
    // 살고있는 도시의 번호 c

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        map[a][b] = min(map[a][b], t);
    }

    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int c;
        cin >> c;
        home.push_back(c);
    }

    // 플로이드로 각 도시별 구간의 최단경로 구하기
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // if (i == j) 
                //     continue;
                if (map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }

    // 각 집에서 n번 도시로 가는 왕복 비용중 최대값을 구한다.
    // 그 중 최소값을 구한다.
    vector<int> answer;

    int answer_min = INF; // 최대값중 최소값

    // 목적지 도시 번호 i
    for (int i = 1; i <= n; i++)
    {
        int nowMax = 0; // 현재 도시들 중에서의 최대값

        // 모든 집 루프용 j
        for (int j = 0; j < home.size(); j++)
        {
            if (home[j] == i) continue;

            int sum = 0;
            sum += map[home[j]][i];
            sum += map[i][home[j]];
            nowMax = max(nowMax, sum);
        }

        // 같으면 도시 번호만 추가하고, 더 작은 값이 나오면 초기화하고 추가
        if (nowMax == answer_min) 
            answer.push_back(i);
        else if (nowMax < answer_min)
        {
            answer_min = nowMax;
            answer.clear();
            answer.push_back(i);
        }
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
}