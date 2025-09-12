#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int>> fireQ;
queue<pair<int, int>> playerQ;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

char map[1002][1002];
int fireDist[1002][1002];
int playerDist[1002][1002];

int t;

/*
	.	공백
	#	벽
	@	시작점
	*	불
	
	불 filled 전에 시작점에서 벽이 없는 외부로 나갈 수 있는가?
	불, player 동시에 bfs
	playerDist <= fireDist	: 성공
	playerDist > fireDist	: 실패 	
*/
void Answer(int, int);

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	

	for (int i = 0; i < t; i++) {
		int w, h;
		cin >> w >> h;
		Answer(w, h);
	}
}

void Answer(int w, int h)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == '@') {
				playerDist[i][j] = -1;
				playerQ.push({ i, j });
			}
			if (map[i][j] == '*') {
				fireDist[i][j] = -1;
				fireQ.push({ i, j });
			}
		}
	}

	// fire 연산 시작
	while (!fireQ.empty()) {
		pair<int, int> cur = fireQ.front(); fireQ.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nowX = cur.first + dx[dir];
			int nowY = cur.second + dy[dir];

			// 외부, 벽, 불에 닿으면 중단
			if (nowX < 0 || nowY < 0 || nowX >= h || nowY >= w) continue;
			if (fireDist[nowX][nowY] > 0) continue;
			if (map[nowX][nowY] == '#' || map[nowX][nowY] == '*') continue;
			fireDist[nowX][nowY] = fireDist[cur.first][cur.second] + 1;
		}
	}

	// player 연산 시작
	while (!playerQ.empty()) {
		pair<int, int> cur = playerQ.front(); playerQ.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nowX = cur.first + dx[dir];
			int nowY = cur.second + dy[dir];

			
			if (playerDist[nowX][nowY] > 0) continue;
			if (map[nowX][nowY] == '#') continue;
			if (fireDist[nowX][nowY] <= playerDist[cur.first][cur.second] + 1) continue;

			// 방문한곳이 아니고, 벽이 아니고, 불이 없는데 외부일 경우
			if (nowX < 0 || nowY < 0 || nowX >= h || nowY >= w) {
				cout << (playerDist[cur.first][cur.second] + 1) + "\n";
				return;
			}

			playerDist[nowX][nowY] = playerDist[cur.first][cur.second] + 1;
		}
	}

	cout << "IMPOSSIBLE\n";
	return;
}
