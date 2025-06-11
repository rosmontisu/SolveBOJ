#include <iostream>
#include <vector>
using namespace std;

int map[402][402];
const int inf = 0x3f3f3f3f;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    // fill ? 인가 있었는데
    for (int i = 1; i < 402; i++)
    {
        for (int j = 1; j < 402; j++)
        {
            map[i][j] = inf;
        }
    }

    /*
    - 일방통행
    - 1 ~ V번까지의 도시
    - 최소 비용의 사이클(시작점으로 돌아오기)
        -왕복도 비용에 포함(왕복만으로 사이클 가능)
    

    
    최소 사이클의 도로 길이의 합을 찾기
    불가능한 경우에는 -1
    */

   int v, e;
   cin >> v >> e;
   for (int i = 0; i < e; i++)
   {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
   }

    // 플로이드, 나한테서 나한테 가는 방향도 찾기
   for (int k = 1; k <= v; k++)
       for (int i = 1; i <= v; i++)
           for (int j = 1; j <= v; j++)
               if (map[i][k] + map[k][j] < map[i][j])
                   map[i][j] = map[i][k] + map[k][j];
    
    int answer = inf;

    for (int i = 1; i <= v; i++)
    {
        if (map[i][i] == inf)
            continue;
        answer = min(answer, map[i][i]);
    }

    if (answer == inf)
        cout << -1;
    else
        cout << answer; 
}