#include <iostream>
#include <string>
#include <math.h>
using namespace std;
char map[5130][5150];

int Height(int n) {
	if (n == 2)
		return 3;
	// f(n-1)*2+1
	return Height(n - 1) * 2 + 1;
}
int Length(int n) {
	if (n == 2)
		return 5;
	// f(n-1)*4+1
	return Height(n - 1) * 4 + 1;
}

void Fractal(int x, int y, int n) {
	if (n == 1) 
	{
		map[x][y] = '*';
		return;
	}
	else 
	{
		int height = Height(n);
		int length = Length(n);

		if (n == 2) {
			length = 5;
			height = 3;
			for (int i = 0; i < length; i++)			// 밑변
				map[x][y + i] = '*';

			for (int i = 0; i < height; i++) {
				map[x + i][y + i] = '*';				// 좌변
				map[x + i][y + length - i - 1] = '*';	// 우변
			}
			map[x + 1][y + 2] = '*';
			return;
		}
	//역삼각
		else if (n % 2 == 0) {
			for (int i = 0; i < length; i++)			// 밑변
				map[x][y + i] = '*';

			for (int i = 0; i < height; i++) {
				map[x + i][y + i] = '*';				// 좌변
				map[x + i][y + length - i - 1] = '*';	// 우변
			}
			Fractal(x, y + length / 4 + 1, n - 1);
		}
	// 정삼각
		else {
			for (int i = 0; i < length; i++)				// 밑변
				map[x + height][y + i] = '*';

			for (int i = 0; i < height; i++) {
				map[x + height - i][y + i] = '*';			// 좌변
				map[x + height - i][y + length - i - 1] = '*';	// 우변
			}
			//map[x][y + height] = '*'; // 꼭짓점
			//map[x + height / 2][y + length / 2] = '*';
			Fractal(x + height / 2 + 1, y + length / 4 + 1, n - 1);

		}
	}
	

}

int main(void) {
	

	int n; 
	cin >> n;
	int height = 1;
	int length = 1;

	// 1. 높이, 밑변일때 n=2 일때의 초기 값은 [3, 5]
	// 2. n=2의 height를 알때, n=3의 값은 -> [height*2+1, (height*2+1)*2-1]
	// 3. 일반화 하면
	// f(n) = [f(n-1)*2 - 1, f(n-1)*4+1]
	// 재귀함수꼴
	if (n > 1) {
		height = Height(n);
		length = Length(n);
	}

	for (int i = 0; i < height; i++)
		for (int j = 0; j < length; j++)
			map[i][j] = ' ';
	
	Fractal(0, 0, n);

	for (int i = 0; i < height + 1; i++) {
		for (int j = 0; j < length + 1; j++)
			cout << map[i][j];
		cout << '\n';
	}

	return 0;
}
