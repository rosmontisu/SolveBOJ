#include <iostream>
#include <algorithm>
using namespace std;

int map[2188][2188];
int n;
int cnt[3];

// 종이 숫자가 전부 같은지 확인 함수
bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (map[x][y] != map[i][j])
				return false;
	return true;
}

void solve(int x, int y, int z)
{
	if (check(x, y, z)) {
		// map[x][y] 에  
		// -1이 들어 있으면 cnt[0]을 올려준다
		//  0이 들어 있으면 cnt[1]을 올려준다
		//  1이 들어 있으면 cnt[2]을 올려준다
		cnt[map[x][y] + 1] += 1;
		return;
	}

	// 종이를 3등분
	int n = z / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			// 현재 위치 + {0, 1, 2} * [3등분값]
			// 왜 {0, 1, 2} 를 곱하나요?
			// -> 종이를 9개로 자르니까 좌표를 보정합니다
			// [초기좌표] + [최대좌표]/3 * {0, 1, 2}
			// ex) x == 9
			// 0 + 9/3 * 0 -> 0
			// 0 + 9/3 * 1 -> 3
			// 0 + 9/3 * 2 -> 6
			// 와 같이 좌표가 나오니까
			// 3등분한 종이의 좌표를 구할 수 있음

			// 보정 좌표를 구한 후 solve함수로 재귀
			// 분할 정복
			solve(x + i * n, y + j * n, n);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	// 종이 채우기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	// 0, 0 부터 시작
	solve(0, 0, n);

	// -1 0 1 로 채워진 종이 3개의 수 출력
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << '\n';

	return 0;
}
