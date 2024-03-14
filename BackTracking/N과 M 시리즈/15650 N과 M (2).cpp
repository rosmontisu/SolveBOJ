#include <iostream>
using namespace std;
int n, m;

// non-decreasing order
// 비내림차순은 중복 입력이 가능하다

// increasing order
// 오름차순은 중복값의 입력이 가능한지 정해져 있지 않다(모호함)

int arr[10];
bool isUsed[10];

// m은 최고 깊이이다.
void dfs(int at, int depth) {
	//base condition
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = at; i <= n; i++) {
		arr[depth] = i;
		dfs(i + 1, depth + 1);
	}
}

int main(void) {
	cin.tie();
	ios::sync_with_stdio(false);

	cin >> n >> m;
	dfs(1, 0);
	return 0;
}
