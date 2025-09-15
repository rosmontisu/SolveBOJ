#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector<vector<int>> dp(505, vector<int>(505, -1));
int map[505][505];

int m, n;

int dfs(int x, int y)
{
    // base case. 탐색 성공
    if (x == m - 1 && y == n - 1) return 1;

    // 방문 검사
    if (dp[x][y] > -1) return dp[x][y];
    dp[x][y] = 0;

    // 델타 탐색
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (map[nx][ny] >= map[x][y]) continue; 

        // 매번 도착지 직전 위치에서 return 받음
        dp[x][y] += dfs(nx, ny);
    }

    // 텔타 탐색이 끝났으므로 이전 좌표로 return
    // 0,0 까지
    return dp[x][y]; 
}

int main()
{
    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
            
    cout << dfs(0, 0);

    return 0;
}