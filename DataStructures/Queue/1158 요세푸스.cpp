#include <iostream>
#include <queue>
#include <string>
using namespace std;


void solve(int n, int k)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}


	cout << "<";
	int tmp = 0;
	while (!q.empty())
	{
		for (int i = 1; i < k; i++)
		{
			tmp = q.front();
			q.push(tmp);
			q.pop();
		}
		cout << q.front();
		q.pop();
		if(!q.empty()){
			cout << ", ";
		}
	}
	cout << ">";
}

void input()
{
	int n, k;
	cin >> n >> k;
	solve(n, k);
}



int main(void)
{
	input();
	//int test;
	//cin >> test;
	return 0;
}
