#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 3*2^10 == 3072
// 3072*2 == 6144
char map[3072][6144];
void Fractal(int x, int y, int n) {
	if (n == 3) {
		map[x][y] = '*';
		map[x + 1][y - 1] = '*'; map[x + 1][y + 1] = '*';
		for (int i = -2; i < 3; i++)
			map[x + 2][y + i] = '*';
	}
	else {
		Fractal(x, y, n / 2);
		Fractal(x+n/2, (y)-(n/2), n / 2);
		Fractal(x+n/2, (y)+(n/2), n / 2);
	}
	// 1. x좌표는 정상적임
	// 2. y좌표에 오차가 잡힘 특히 우하변이 문제인듯?
	// n 을 기준으로 재귀를 돌리니까 문제가 생긴다
	// 같은 n을 가지고 좌하와 우하를 처리하면? 당연히 같은 값이 나오니까..
	// 이전의 x, y 를 기준으로 다시 구해보자
}

int main(void) {
	for (int i = 0; i < 3072; i++)
		for (int j = 0; j < 6144; j++)
			map[i][j] = ' ';
	int n; cin >> n;
	Fractal(0, n - 1, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++)
			cout << map[i][j];
		cout << '\n';
	}	
}
