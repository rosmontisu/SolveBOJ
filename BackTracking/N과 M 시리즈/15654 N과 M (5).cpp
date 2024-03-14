#include <iostream>
using namespace std;

int n, m;
int nums[10];

int answer[10];
bool isUsed[10001];

void sort(int* arr) {
	for (int i = 0; i < n-1; i++) {
		int cur = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[cur] >= arr[j]) {
				cur = j;
			}
		}
		swap(arr[i], arr[cur]);
	}
}

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}	
	for (int i = 0; i < n; i++) {
		if (!isUsed[nums[i]]) {
			isUsed[nums[i]] = true;
			answer[depth] = nums[i];
			dfs(depth + 1);
			isUsed[nums[i]] = false;
		}		
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums);
	// for (int i = 0; i < n; i++) {
	// 	cout << nums[i] << ' ';
	// }
	// cout << '\n';
	dfs(0);

	return 0;
}
