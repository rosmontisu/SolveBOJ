#include <iostream>
using namespace std;

int n, m;
int arr[8];
bool isUsed[8];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int sPoint = 1; // 시작지점 초기값
	if (k != 0)
		sPoint = arr[k - 1] + 1;

	for (int i = sPoint; i <= n; i++) {
		if (!isUsed[i]) {
			arr[k] = i;
			isUsed[i] = true;
			func(k + 1);
			isUsed[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> n >> m;
	func(0);
	return 0;
}
