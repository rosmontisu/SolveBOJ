#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[51][51];
bool visit[51][51];

// flood 방향 4개
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int n, m, k, x, y;

void Bfs(int nx, int ny) {
	visit[nx][ny] = true;
	queue<pair<int, int>> Q; 
	Q.push({ nx, ny });
	
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == 0) continue;
			
			visit[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}
}
int Area()
{
	// 다른 테스트 케이스에서 이용한 배열을 초기화해야한다.
	for (int i = 0; i < m; i++) {
		fill(visit[i], visit[i] + n, false);
	}
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				Bfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> m >> n >> k;

		// 미리 map을 초기화 시켜야한다.
		for (int i = 0; i < m; i++)
			fill(map[i], map[i] + n, 0);

		while (k--) {
			cin >> x >> y;
			map[x][y] = 1;
		}
		cout << Area() << '\n';
	}
}
