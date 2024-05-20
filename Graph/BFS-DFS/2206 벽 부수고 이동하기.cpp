#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1002][1002];
int dist[1002][1002];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int answer = 1000002;

/*
bfs로 돌릴때 매번 1번씩 벽을 부수어 보면될거같다
*/

void Bfs()
{
    bool destroyChance = true;
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    while(q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
            if (map[nx][ny]) continue;     

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            if (nx == n && ny == m)
                answer = min(answer, dist[nx][ny]);
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    Bfs();
    if (answer < 1000002)
        cout << answer;
    else
        cout << -1; 
}