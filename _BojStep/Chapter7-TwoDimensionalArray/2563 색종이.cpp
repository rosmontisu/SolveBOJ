#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	bool map[100][100] = { false };
	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++)
			for (int j = y; j < y + 10; j++)
				map[i][j] = true;
	}

	int count = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j])
				count++;
	cout << count;
}