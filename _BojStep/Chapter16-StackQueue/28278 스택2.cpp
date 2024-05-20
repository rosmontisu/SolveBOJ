#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	stack<int> stk;
	for (int i = 0; i < n; i++)
	{
		int o, x;
		cin >> o;
		if (o == 1)
		{
			cin >> x;
			stk.push(x);
		}
		else if (o == 2)
		{
			if (!stk.empty())
			{
				cout << stk.top() << '\n';
				stk.pop();
			}
			else
				cout << -1 << '\n';
		}
		else if (o == 3)
			cout << stk.size() << '\n';
		else if (o == 4)
			cout << (stk.empty() ? 1 : 0) << '\n';
		else
			cout << (stk.empty() ? -1 : stk.top()) << '\n';
	}
}