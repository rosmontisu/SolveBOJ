//4n-3 꼴로 길이가 나온다 

#include <iostream>
#include <vector>
#include <string>
using namespace std;
char map[400][400];

void Fractal(int x, int y, int n) {
	if (n == 1) {
		map[x][y] = '*';
		return;
	}

	int length = 4 * n - 3;

	for (int i = 0; i < length; i++) {
		map[x][y+i] = '*'; // 상변
		map[x+i][y] = '*'; // 좌변
		map[x+length - 1][y+i] = '*'; // 하변
		map[x+i][y+length - 1] = '*'; // 우변
	}

	Fractal(x + 2, y + 2, n - 1);
}

int main(void) {
	int n; cin >> n;
	int length = 4 * n - 3;
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			map[i][j] = ' ';
	
	Fractal(0, 0, n);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++)
			cout << map[i][j];
		cout << '\n';
	}
		
	return 0;
}
