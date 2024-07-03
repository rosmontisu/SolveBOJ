#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> nums;
vector<int> answer;

int isUsed[10];

void dfs(int at, int depth)
{
	if (depth == m)
	{
		for (auto i : answer)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = at; i < m ;i++)
	{
		answer.push_back(nums[i]);
		dfs(i, depth+1);
		answer.pop_back();
	}
	

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >>input;
		answer.push_back(input);
	}

	
	cout << "asdf";

	sort(nums.begin(), nums.end());
	dfs(0, 0);
	cout << "asdf";

	return 0;
}