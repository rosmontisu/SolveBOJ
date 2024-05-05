#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int x, s; // 돈, 공격력
	cin >> x >> s;

	int maxAtk = 0;
	while (n--)
	{
		int c, p; // 가격, 무기 공격력
		cin >> c >> p;
		if (c <= x)
			if (maxAtk < p)
				maxAtk = p;
	}

	if (maxAtk > s)
		cout << "YES";
	else
		cout << "NO";
}