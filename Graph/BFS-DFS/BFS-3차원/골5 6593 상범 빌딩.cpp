#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

char map[100][100][100];
int dist[100][100][100];

int dx[6] = { -1, 0, 1, 0, 0, 0 };
int dy[6] = { 0, -1, 0, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

queue<tuple<int, int, int>> Q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, c;
    while (true)
    {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            return 0;

        while (!Q.empty()) Q.pop(); // 큐 초기화

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> map[i][j][k];
                    dist[i][j][k] = -1; // 모든 칸을 미방문(-1)으로 초기화
                    if (map[i][j][k] == 'S')
                    {
                        Q.push({ i, j, k });
                        dist[i][j][k] = 0; // 시작 지점 거리 = 0
                    }
                }
            }
        }

        int ans = 30*30*30 + 1; // INF
        bool isExit = false;

        while (!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();
            
            int curZ, curY, curX;
            tie(curZ, curY, curX) = cur; // 층 행 열

            for (int dir = 0; dir < 6; dir++)
            {
                int nz = curZ + dz[dir]; // 다음 층
                int ny = curY + dy[dir]; // 다음 행
                int nx = curX + dx[dir]; // 다음 열

                // 유효 범위 검사
                if (nz < 0 || nz >= l || ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                // 이미 방문 or 벽
                if (dist[nz][ny][nx] >= 0 || map[nz][ny][nx] == '#') continue;

                // 출구 - 거리기록/BFS 중단 (BFS 특징 잊지말기, flood fill -> 먼저 나오는게 최단 거리)
                if (map[nz][ny][nx] == 'E')
                {
                    ans = dist[curZ][curY][curX] + 1;
                    isExit = true;
                    while (!Q.empty()) Q.pop(); // 큐 비워서 BFS 즉시 종료
                    break;
                }

                // 계속 탐색 진행
                dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;
                Q.push({ nz, ny, nx });
            }
            if (isExit) break; // 출구를 찾았으니 중단
        }

        if (ans == 30*30*30 + 1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << ans << " minute(s).\n";
    }

    return 0;
}