#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[10][10];
bool visit[10][10];
int n, m;
int answer = 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int copy_map[10][10];

// 배열을 모두 초기화 시켜줍니다
void Init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            copy_map[i][j] = map[i][j];
            visit[i][j] = false;
        }         
}
void Bfs()
{
    // bfs 돌려서 모든 바이러스를 퍼뜨리고
    // 배열을 검색해서 0의 갯수를 answer에 넣습니다
    Init();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && copy_map[i][j] == 2)
            {
                visit[i][j] = true;
                queue<pair<int, int>> q;
                q.push({ i, j });

                while (!q.empty())
                {
                    pair<int, int> cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (copy_map[nx][ny] == 1) continue; // 1은 벽
                        if (visit[nx][ny]) continue;

                        copy_map[nx][ny] = 2; // 바이러스 2
                        visit[nx][ny] = true;
                        q.push({ nx, ny });
                    }
                }
            }
        }
    }

    int safe = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (copy_map[i][j] == 0)
                safe++;
    answer = max(safe, answer);
}

// 반복문으로 구현하면 너무 복잡하니까 재귀로 벽을 구현합시다
void Wall(int count)
{
    if (count == 3)
    {
        Bfs();
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                Wall(count + 1);
                map[i][j] = 0; // 3개의 벽을 모두 만들었으니까, 마지막 벽을 다시 0으로 바꾸기
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
    Wall(0);
    cout << answer;
}