#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[1002][1002];
int dist[1002][1002];
queue<pair<int, int>> Q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m; // 0-x | 1-o | 2-goal
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				dist[i][j] = -1;
			if (map[i][j] == 2)
				Q.push({ i,j });
		}
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (map[nx][ny] == 0) continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (dist[nx][ny] >= 0) continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1; // 거리 + 1
			Q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << "\n";
	}

}
