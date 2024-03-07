#include <iostream>
#include <vector>
#include <string>
using namespace std;
char map[400][400];

void Fractal(int x, int y, int n) {
	int length = 4 * n - 3;

	if (n == 1)
		map[x][y] = '*';
	else {
		for (int i = 0; i < length+1; i++)
			map[x][y + i] = '*'; // 상변
		for (int i = 0; i < length; i++) 
			map[x + length + 1][y + i] = '*'; // 하변
		for (int i = 0; i < length + 1; i++)
			map[x + i][y] = '*'; // 좌변
		for (int i = 0; i < length - 1; i++)
			map[x + 2 + i][y + length - 1] = '*'; // 우변

		Fractal(x + 2, y + 2, n - 1);
	}

	if (n == 2) {
		map[x + 2][y + 2] = '*';
		map[x + 2][y + 3] = '*';
		map[x + 3][y + 2] = '*';
		map[x + 4][y + 2] = '*';
	}
}

int main(void) {
	for (int i = 0; i < 400; i++)
		for (int j = 0; j < 400; j++)
			map[i][j] = ' ';
	int n; cin >> n;
	int length = 4 * n - 3;

	Fractal(0, 0, n);

	for (int i = 0; i < length+2; i++) {
		for (int j = 0; j < length; j++) {

			// 해당 문제의 2번째 줄은 *뒤에 공백이 없다.
			// 고로 *하나만 출력하고 반복문을 break
			if (i == 1) {
				cout << map[i][j];
				break;
			}
			cout << map[i][j];
		}
		cout << '\n';
	}
		
	return 0;
}
