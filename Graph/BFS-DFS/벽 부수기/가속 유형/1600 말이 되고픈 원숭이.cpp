#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dxk[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dyk[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int map[205][205];
int dist[205][205][35];

int main()
{
    int k, w, h;
    cin >> k >> w >> h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> map[i][j];
        }
    }

    // 1,1에서 시작해서
    // w,h에 도착하기

    queue<tuple<int, int, int>> q;
    q.push({ 1, 1, 0 }); // x, y, knight
    dist[1][1][0] = 1; // dist 1로 초기화, 답에 -1 필요
    while (!q.empty())
    {
        int x, y, knight;
        tie(x, y, knight) = q.front(); q.pop();
        // 1. 나이트 점프가 가능한 상황
        if (knight < k)
        {
            // 나이트 점프 x
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nk = knight;
                
                if (nx < 1 || ny < 1 || nx > w || ny > h) continue;
                if (map[ny][nx] > 0) continue;
                if (dist[ny][nx][nk] > 0) continue;

                dist[ny][nx][nk] = dist[y][x][knight] + 1;
                q.push({ nx, ny, nk });
            }

            // 나이트 점프 o
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = x + dxk[dir];
                int ny = y + dyk[dir];
                int nk = knight + 1;
                
                if (nx < 1 || ny < 1 || nx > w || ny > h) continue;
                if (map[ny][nx] > 0) continue;
                if (dist[ny][nx][nk] > 0) continue;

                dist[ny][nx][nk] = dist[y][x][knight] + 1;
                q.push({ nx, ny, nk });
            }
        }
        // 2. 나이트 점프가 불가능한 상황
        else
        {
            // 나이트 점프 x
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nk = knight;
                
                if (nx < 1 || ny < 1 || nx > w || ny > h) continue;
                if (map[ny][nx] > 0) continue;
                if (dist[ny][nx][nk] > 0) continue;

                dist[ny][nx][nk] = dist[y][x][knight] + 1;
                q.push({ nx, ny, nk });
            }
        }
    }

    int answer = w*h+1;
    for (int i = 0; i <= k; i++)
    {
        if (dist[h][w][i] > 0)
            answer = min(answer, dist[h][w][i]);
    }

    if (answer < w*h+1)
        cout << answer - 1;
    else
        cout << -1;
}