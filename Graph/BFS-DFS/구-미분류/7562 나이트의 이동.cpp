#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool visit[301][301];
int dist[301][301];

// 나이트의 이동경로 8개
int dx[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int L, sx, sy, tx, ty;

int Bfs() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			dist[i][j] = 0;
			visit[i][j] = false;
		}
	}

	visit[sx][sy] = true;
	queue<pair<int, int>> Q; 
	Q.push({ sx, sy });
	
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		if (tx == cur.first && ty == cur.second) {
			return dist[tx][ty];
		}

		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			
			if (nx < 0 || ny < 0 || nx >= L || ny >= L) continue;
			if (visit[nx][ny]) continue;
			
			visit[nx][ny] = true;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	
	while (T--)
	{
		cin >> L;
		cin >> sx >> sy; // 초기위치
		cin >> tx >> ty; // 목표
		cout << Bfs() << '\n';
	}
}
