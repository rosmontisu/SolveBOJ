/*
수열은 사전 순으로 증가하는 순서로 출력해야 한다.
3 3
1231 1232 1233

1231 1231 1231
1231 1231 1232
1231 1231 1233
1231 1232 1231
1231 1232 1232
1231 1232 1233
...
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

vector<int> arr;
vector<int> answer;


void dfs(int cur, int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}

	// 이번 문제는 더 깊은 dfs에서도 루프를 모두 돌리니까
	// cur가 필요없네요
	for (int i = 0; i < n; i++)
	{
		answer.push_back(arr[i]);
		//depth++;
		dfs(i, depth + 1);
		answer.pop_back();
		//depth--;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int input; cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());
	dfs(0, 0);

	return 0;
}