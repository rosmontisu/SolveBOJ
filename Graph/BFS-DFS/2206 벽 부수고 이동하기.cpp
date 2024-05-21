#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1002][1002];
int map_copy[1002][1002];
int dist[1002][1002];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int answer = 1000002;

/*
벽 1개가 제거된 모든 경우의 수에서 BFS를 돌린 후, 최단 경로를 서치?
*/

// 배열을 모두 초기화 시켜줍니다
void Init()
{
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            map_copy[i][j] = map[i][j];
            dist[i][j] = 0;
        } 
    }
}

void Bfs()
{
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    dist[1][1] = 1; // 항상 시작점을 거리 1로 계산합니다.
    while(!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 1 || ny < 1 || nx > n || ny > m) continue; // 범위 설정 잘하기 <- 여기서 계속 오류
            if (map_copy[nx][ny] == 1 || dist[nx][ny] > 0) continue;     

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({ nx, ny });
            if (nx == n && ny == m)
                answer = min(answer, dist[nx][ny]);
        }

    }
}
void Answer()
{  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j])
            {
                Init(); 
                map_copy[i][j] = 0; // 벽을 허물고 
                Bfs(); // 검사 
            }
        }
    }
    Init(); 
    Bfs(); // 벽을 허물지 않는 경우도 1번 검사
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j <= m; j++)
            map[i][j+1] = s[j] - '0';
    }
    Answer();
    if (answer < 1000002)
        cout << answer;
    else
        cout << -1; 
}