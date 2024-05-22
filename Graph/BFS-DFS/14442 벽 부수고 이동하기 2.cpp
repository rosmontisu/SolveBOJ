#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n, m, k;
int map[1010][1010];
int dist[1010][1010][12];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Bfs()
{
    queue<tuple<int, int, int>> q;
    dist[1][1][0] = 1;
    q.push({1, 1, 0});
    while(!q.empty())
    {
        int x, y, wall_count;
        tie(x, y, wall_count) = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int distance = dist[x][y][wall_count] + 1;

            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (nx == n && ny == m) 
            {
                dist[nx][ny][wall_count] = distance;
                break;
            }
            // 벽이 있다면?
            if (map[nx][ny] == 1)
            {
                if(wall_count == k) continue; // 최고 차원이면 중단
                if(dist[nx][ny][wall_count+1] > 0) continue; // 벽이 있다면, 해당 차원에서 해당 위치는 어차피 방문이 불가하므로, 상위차원의 방문 여부만 검사하면된다.
                                                             
                dist[nx][ny][wall_count+1] = distance;// 상위 차원의 거리를 수정해야합니다!!!
                q.push({nx, ny, wall_count + 1});
            }
            // 벽이 없다면?
            else
            {
                if (dist[nx][ny][wall_count] > 0) continue; 
                dist[nx][ny][wall_count] = distance;
                q.push({nx, ny, wall_count});
            }
        }
    }
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
    
    Bfs();
    int answer = MAX_NUM;

    for (int i = 0; i <= k; i++) // i < k 가 문제였다
        if(dist[n][m][i] > 0)
            answer = min(answer, dist[n][m][i]);
    if (answer == MAX_NUM)
        answer = -1;
    cout << answer;
    return 0;
    /*
    k가 벽을 부술 수 있는 최대 개수입니다. 
    즉, k=5면 5개의 벽을 부시는게 가능하므로
    0개를 부시는 차원부터
    5개를 부시는 차원까지
    총 6개가 필요하므로, 마지막 main의 루프문에서 i <= k 가 맞습니다
    */
}