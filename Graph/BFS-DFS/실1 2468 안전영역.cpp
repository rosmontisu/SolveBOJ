#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[102][102];
bool vis[102][102];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int n, ans, height, area;

void ResetVis()
{
    fill(&vis[0][0], &vis[0][0] + 102 * 102, false);
}

void Bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({ i, j });
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue; // map 나감
            if (vis[nx][ny]) continue; // 이미 방문
            if (map[nx][ny] <= height) continue; // 이미 물에 잠김
            
            vis[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
    
    area++;
}

int main()
{
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            height = max(height, map[i][j]);
        }
    }
        
    
    while(height--)
    {
        ResetVis();
        area = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!vis[i][j] && map[i][j] > height) // 미방문 & 미침수지역
                    Bfs(i, j);
            }
        }
        
        ans = max(ans, area);
    }
    
    
    cout << ans;
}