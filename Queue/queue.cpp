#include <iostream>
#include <queue>
using namespace std;

void input()
{
	int n, k;
	cin >> n >> k;
	solve(n, k);
}

void solve(int n, int k)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	int tmp = 0;
	while (!q.empty)
	{
		for (int i = 1; i < k; i++)
		{
			tmp = q.pop();
			q.push(tmp);
		}
		cout << q.pop() << " ";

	}
}

int main(void)
{
	input();
	solve();
	return 0;
}