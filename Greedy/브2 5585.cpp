#include <iostream>
using namespace std;

int main()
{
	// 500, 100, 50, 10, 5, 1

	int n, count = 0;
	cin >> n;

	n = (1000 - n);

	while (n > 0)
	{
		if (n >= 500)
		{
			n -= 500;
			count++;
		}
		else if (n >= 100)
		{
			n -= 100;
			count++;
		}
		else if (n >= 50)
		{
			n -= 50;
			count++;
		}
		else if (n >= 10)
		{
			n -= 10;
			count++;
		}
		else if (n >= 5)
		{
			n -= 5;
			count++;
		}
		else
		{
			n -= 1;
			count++;
		}
	}

	cout << count;
}