#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> nums;
vector<int> answer;
bool isUsed[10001];

void dfs(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return; 
	}

	// 수열의 중복을 피하기 위해서, lastNum 변수를 만들었습니다.
	// 이때, 변수의 위치에 주의하여야합니다. 
	// 전역 변수의 형태로 선언하면 정상적으로 작동 x
	int lastNum = 0;
	for (int i = 0; i < n; i++)
	{
		if(!isUsed[i] && lastNum != nums[i])
		{
			isUsed[i] = true;
			lastNum = nums[i];
			answer.push_back(nums[i]);
			dfs(depth + 1);
			answer.pop_back();
			isUsed[i] = false;
		}
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
		cin >> input;
		nums.push_back(input);
	}

	sort(nums.begin(), nums.end());
	dfs(0);

	return 0;
}