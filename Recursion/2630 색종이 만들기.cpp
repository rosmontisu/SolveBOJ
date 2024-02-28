#include <iostream>
#include <algorithm>
using namespace std;
// map - > n*n
// n = 2^k, (1 <= k <= 7) ... 256

int map[257][257];
int cnt[2];



bool check(int x, int y, int n) {
	for (int i = x; i < x+n; i++)
		for (int j = y; j < y+n; j++)
			if (map[i][j] != map[x][y])
				return false;
	return true;
}

void solve(int x, int y, int n) {

	if (check(x, y, n)) {
		cnt[map[x][y]] += 1;
		return;
	}

	int cutN = n / 2;
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++)
			// 자른 종이 좌표 보정
			solve(x + i * cutN, y + j * cutN, cutN);
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

	solve(0, 0, n);
	
	cout << cnt[0] << '\n';
	cout << cnt[1] << '\n';

	return 0;
}
