#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int map[103][103][103]; // 맵
int dist[103][103][103]; // distance

int dx[6] = { -1, 0, 1, 0, 0, 0}; // 전, 좌, 후, 우, 상, 하
int dy[6] = { 0, -1, 0, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

queue<tuple<int, int, int>> Q; // bfs 현재 탐색 시작점

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, h; // 가로, 세로, 높이;
    cin >> m >> n >> h;

    // 1. map과 dist 초기 설정
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> map[j][k][i];
                if (map[j][k][i] == 1) {
                    Q.push({ j, k, i }); // dist는 이미 0으로 초기화
                }
                if (map[j][k][i] == 0) {
                    dist[j][k][i] = -1;
                }
            }
        }
    }

    // 2. 너비 우선 탐색 시작
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        Q.pop();

        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;

        for (int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue; // 범위를 벗어나는가?
            if (dist[nx][ny][nz] >= 0 || map[nx][ny][nz] == -1)
                continue; // 이미 탐색 하였거나 공백인가?

            // 탐색 완료, 커서값에 +1
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            Q.push({ nx, ny, nz });
        }
    }

    int answer = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[j][k][i] == -1 && map[j][k][i] != -1) {
                    cout << -1;
                    return 0;
                }
                answer = max(answer, dist[j][k][i]);
            }
        }
    }
    cout << answer;
    return 0;
}
