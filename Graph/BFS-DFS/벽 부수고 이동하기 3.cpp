#include <iostream>
#include <queue> 
#include <tuple> 
using namespace std;
/*
첫 번째 풀이처럼 벽이 부서진 모든 경우의 수로 풀면
시간 초과가 발생
시간복잡도가 대략 O(n^2 * m^2) 
엄~청 느리다!

고로, 벽을 만날때만 벽을 허무는 연산을 수행하도록 코드를 수정해보자
- dist[] 배열을 3차원으로 수정해서, 벽이 부시기전까지의 거리를 측정하다가, 벽을 부순 후 다른 차원에서 이어서 거리를 계산
    dist[x][y][0]은 벽이 있는 상태 에서의 최단 거리
    dist[x][y][1]은 벽을 허문 상태 에서의 최단 거리

    dist[x][y][0]상태에서 벽을 만나면 벽을 허물고 연산을 수행하도록 해보자
*/
int n, m;
int map[1002][1002];
int dist[1002][1002][2];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
void Bfs()
{
    queue<tuple<int, int, int>> q; // (x, y, wall_break_status) 
    q.push({1, 1, 0});
    dist[1][1][0] = 1;
    while (!q.empty())
    {
        int x, y, wall_chance;
        tie(x, y, wall_chance) = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int distance = dist[x][y][wall_chance] + 1;

            if (nx < 1 || ny < 1 || nx > n || ny > m) continue; // 범위 체크 
            // 벽을 만나지 않았고, 처음 방문했는데, 이전보다 효율적인 거리라면
            if (map[nx][ny] == 0 && dist[nx][ny][wall_chance] <= 0)
            {      
                dist[nx][ny][wall_chance] = distance;
                q.push({nx, ny, wall_chance}); 
            } 

            // 벽을 만났고, 처음 방문했고, 벽을 부실 기회가 있다면
            // 벽을 부순 차원으로 이동해서 PUSH
            if (map[nx][ny] == 1 && dist[nx][ny][wall_chance] <= 0 && wall_chance == 0)
            { 
                dist[nx][ny][1] = distance; 
                q.push({nx, ny, 1}); 
            } 
        } 
    } 
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
        for (int j = 0; j < m; j++) 
            map[i][j+1] = s[j] - '0';
    } 
    dist[n][m][0] = -1;
    dist[n][m][1] = -1;

    Bfs(); 
    
    // 둘 중 하나가 음수면, 양수인 값을
    // 둘 모두 음수/양수면 가장 작은 값을
    if(dist[n][m][0] * dist[n][m][1] < 0)
        cout << max(dist[n][m][0], dist[n][m][1]); 
    else
        cout << min(dist[n][m][0], dist[n][m][1]); 
 
    return 0; 
}
