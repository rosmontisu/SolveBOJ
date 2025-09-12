#include <iostream>
#include <queue>
using namespace std;

int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int dy[8] = { 1, 0, -1, 0, -1, 1, 1, -1 };

int map[55][55];
bool visit[55][55];

int main()
{
    while (true)
    {
        int w, h;
        cin >> w >> h;
        if (w + h == 0) return 0;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                visit[i][j] = false;
                cin >> map[i][j];
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (!visit[i][j] && map[i][j])
                {
                    visit[i][j] = true;
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    while (!q.empty())
                    {
                        auto cur = q.front(); q.pop();
                        for (int dir = 0; dir < 8; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            
                            if (nx < 1 || ny < 1 || nx > h || ny > w) continue;
                            if (visit[nx][ny]) continue;
                            if (map[nx][ny] == 0) continue;
                            
                            q.push({ nx, ny });
                            visit[nx][ny] = true;
                        }
                    }
                }
            }
        }
        
        cout << ans << '\n';
    }
}