#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
백트래킹 문제는 재귀적인 형태로 풀이가 가능하다.
가능한 모든 시작점에서 모든 경우의 수에 대해 최대 깊이까지 탐색한다.

n개의 자연수, m길이의 수열

1. 입력받는 n개의 자연수 중에서 m개를 고른다.
2. 같은 수의 중복이 가능하다.
3. 고른 수열은 비내림차순이다.

--------------------------
1. 입력받은 n개의 수를 오름차순으로 정렬
2. 가장 작은 수부터 커지는 순으로 시뮬레이션
- 이때 깊이는 m
- 시작점의 수는 n

n개의 시작점을 루프돌리면서 더 깊은곳에서 다시 n-1루프
어디까지? depth가 목표에 도착할때까지

유의점은 다른 n&m 문제와 다르게 중복(isUsed)검사가 필요없고, 대신 오름차순(비내림차순)검사(now >= before) or 현재 사용중인 배열 위치 정보가 필요하다.
*/

vector<int> nums;
int n, m;

vector<int> answer;
bool isUsed[10001]; // n개의 수의 사용 여부를 담을 배열

void dfs(int start, int depth)
{
	if(depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++)
	{
		answer.push_back(nums[i]);
		dfs(i, depth+1);
		answer.pop_back();
	}
}


int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		nums.push_back(input);
	}

	sort(nums.begin(), nums.end());
	dfs(0, 0);

	return 0;
}