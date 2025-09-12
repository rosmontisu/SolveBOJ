#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n, m, k;
int map[1010][1010];
int dist_t[12][1010][1010] = { -1 };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int Bfs()
{
    queue<tuple<int, int, int>> q;
    dist_t[0][1][1] = 1;
    q.push({1, 1, 0});
    if (n == 1 && m == 1) return 1; // 예외 목적지
    while(!q.empty())
    {
        int x, y, wall_count;
        tie(x, y, wall_count) = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int distance = dist_t[wall_count][x][y] + 1;

            if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue; // map 이탈
            if (dist_t[wall_count][nx][ny] > 0) continue; // 이미 방문함
            if (nx == n && ny == m) return distance; // 목적지에 도착함

            // 벽이 있다면?
            if (map[nx][ny] && wall_count < k)
            {
                if(dist_t[wall_count+1][nx][ny] > 0) continue; // 벽이 있다면, 해당 차원에서 해당 위치는 어차피 방문이 불가하므로, 상위차원의 방문 여부만 검사하면된다.
                /*
                BFS의 특성상 이미 방문한 곳에 뒤늦게 방문했다는 말은 
                현재 경로가 절대로 더 빠른 경로가 될 수 없다는 말이다.
                */
                                                             
                dist_t[wall_count+1][nx][ny] = distance;// 상위 차원의 거리를 수정해야합니다!!!
                q.push({nx, ny, wall_count + 1});
            }
            // 벽이 없다면?
            if(!map[nx][ny] && dist_t[wall_count][nx][ny] <= 0)
            {
                dist_t[wall_count][nx][ny] = distance;
                q.push({nx, ny, wall_count});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cin >> n >> m >> k;
    const int MAX_NUM = 1004004;
    
    for (int i = 1; i <= n; i++)
    {
        string s; 
        cin >> s;
        for (int j = 0; j < m; j++)
            map[i][j+1] = s[j] - '0';
    }

    cout << Bfs();
    return 0;
}