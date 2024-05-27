#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> chars;
vector<int> answer;
bool isUsed[10001];


void dfs(int depth, int cur)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = cur; i < n; i++)
	{
		if (!isUsed[i])
		{
			isUsed[i] = true;
			answer.push_back(chars[i]);
			dfs(depth + 1, i);
			answer.pop_back();
			isUsed[i] = false;
		}
		
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		chars.push_back(input);
	}	

	sort(chars.begin(), chars.end());
	dfs(0, 0);

	return 0;
}