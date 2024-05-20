#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int arr[9][9];
	int max = 0;
	int ay, ax;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			int n; cin >> n;
			arr[i][j] = n;
			if (max <= n)
			{
				ay = i+1; ax = j+1;
				max = n;
			}
		}

	cout << max << '\n' << ay << ' ' << ax;
	return 0;
}