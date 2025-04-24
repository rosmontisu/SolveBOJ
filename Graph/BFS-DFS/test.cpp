#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int map[1002][1002];
int dist[1002][1002];
vector<pair<int, int>> adj[1002][1002]; // 인접 리스트

int ans = 0;
int m, n;

int main()
{
    cin >> m >> n;
    
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1) q.push({ i, j });
            if (map[i][j] == 0) dist[i][j] = -1;
        }
    }   
    
    // 인접 리스트 생성
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
                {
                    adj[i][j].push_back({nx, ny});
                }
            }
        }
    }
    
    // BFS
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        for (auto &neighbor : adj[cur.first][cur.second])
        {
            int nx = neighbor.first;
            int ny = neighbor.second;
            
            if (dist[nx][ny] != -1) continue;
            
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    
    // 결과 계산
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    
    cout << ans;
    return 0;
}