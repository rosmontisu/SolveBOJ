#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int TC, bX, bY;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 내가 멀 틀린겅림,,?
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> TC;
	for (int testNo = 0; testNo < TC; testNo++) {
		bool escape = false;
		queue<pair<int, int>> Qf = {}, Qs = {};

		cin >> bY >> bX;
		// fill(&ptr1, &ptr2, [init_num]
		// 방문값 0으로 초기화
		for (int i = 0; i < bX; i++) {
			fill(visF[i], visF[i] + bY, 0);
			fill(visS[i], visS[i] + bY, 0);
		}

		// 보드 생성
		for (int i = 0; i < bX; i++) {
			for (int j = 0; j < bY; j++) {
				char c; cin >> c;
				if (c == '#') board[i][j] = -1;
				else {
					if (c == '@') {
						Qs.push({ i, j });
						visS[i][j] = 1;
					}
					else if (c == '*') {
						Qf.push({ i, j });
						visF[i][j] = 1;
					}
					board[i][j] = 0;
				}
			}
		}

		// fire 기준으로 bfs 루프 돌리기
		while (!Qf.empty()) {
			auto cur = Qf.front();
			Qf.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cur.X + dx[k];
				int ny = cur.Y + dy[k];
				if (nx < 0 || ny < 0 || bX <= nx || bY <= ny) continue;
				if (board[nx][ny] == -1) continue;	// 벽
				if (visF[nx][ny]) continue;			// 이미 불이 번짐
				visF[nx][ny] = visF[cur.X][cur.Y] + 1;
				Qf.push({ nx, ny });
			}
		}

		// player bfs 루프 돌ㄹ.기
		while ((!Qs.empty()) && (!escape)) {
			auto cur = Qs.front(); Qs.pop();
			for (int k = 0; k < 4; k++) {
				int nx = cur.X + dx[k];
				int ny = cur.Y + dy[k];

				// 맵 밖으로 나가면
				if (nx < 0 || ny < 0 || bX <= nx || bY <= ny) {
					cout << visS[cur.X][cur.Y] << '\n';
					escape = true;
					break;
				}
				if (board[nx][ny] == -1) continue;  // 벽
				if (visS[nx][ny]) continue;			// 방문함
				if (visF[nx][ny] != 0 &&			// 불이 온적 있다면?
					visF[nx][ny] <= visS[cur.X][cur.Y] + 1) continue;	// 불의 dist와 비교
				visS[nx][ny] = visS[cur.X][cur.Y] + 1;
				Qs.push({ nx, ny });
			}
		}
		if (!escape)
			cout << "IMPOSSIBLE" << '\n';
	}
}
