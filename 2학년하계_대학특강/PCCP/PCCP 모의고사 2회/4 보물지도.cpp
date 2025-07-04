#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int map[1005][1005];
int dist[1005][1005][2];

int solution(int n, int m, vector<vector<int>> hole) 
{
    int answer = 0;
    
    // map 에 구멍 등록
    for (auto h : hole)
    {
        map[h[1]][h[0]] = 1;
    }
    
    queue<tuple<int, int, int>> q; // x, y, boosted
    q.push({ 1, 1, 0 });
    dist[1][1][0] = 1;
    while (!q.empty())
    {
        int x, y, isBoosted;
        tie(x, y, isBoosted) = q.front(); q.pop();
        
        // 1. boost 미사용 상태
        if (isBoosted == 0)
        {
            // boost - 사용 x
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if (nx < 1 || ny < 1 || nx > n || ny > m) continue; // 맵나감
                if (dist[ny][nx][0] != 0) continue; // 이미 방문
                if (map[ny][nx] == 1) continue; // 함정
                
                dist[ny][nx][0] = dist[y][x][0] + 1; 
                q.push({ nx, ny, 0 });
            }
            
            // boost - 사용 o
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir] * 2;
                int ny = y + dy[dir] * 2;
                
                if (nx < 1 || ny < 1 || nx > n || ny > m) continue; // 맵나감
                if (dist[ny][nx][1] != 0) continue; // 이미 방문
                if (map[ny][nx] == 1) continue; // 함정
                
                dist[ny][nx][1] = dist[y][x][0] + 1; 
                q.push({ nx, ny, 1 });
            }
            
        }
        // 2. boost 사용 상태
        else
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if (nx < 1 || ny < 1 || nx > n || ny > m) continue; // 맵나감
                if (dist[ny][nx][1] != 0) continue; // 이미 방문
                if (map[ny][nx] == 1) continue; // 함정
                
                dist[ny][nx][1] = dist[y][x][1] + 1; 
                q.push({ nx, ny, 1 });
            }
        }
    }
    
    int ans1 = dist[m][n][0];
    int ans2 = dist[m][n][1];
    
    // return ans1; 
    // return ans1;
    if (ans1 > 0 && ans2 > 0)
        return min(ans1, ans2) - 1;
    else if (ans1 == 0 && ans2 == 0)
        return -1;
    else
        return max(ans1, ans2) - 1;

}