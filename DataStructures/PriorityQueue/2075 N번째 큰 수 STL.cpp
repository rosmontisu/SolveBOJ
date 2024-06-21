#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 최소힙은 데이터를 음수로 넣어서 구현한다.
	// 참고 : https://kbj96.tistory.com/15
	priority_queue<int, vector<int>, greater<>> q;

	int n;
	cin >> n; 
	for (int i = 0; i < n * n; i++)
	{
		int input;
		cin >> input;
		q.push(input);

		// STL사용한 첫번째 트라이에서 메모리가 초과함.
		// 상위 n개의 데이터만 필요하므로, size가 n을 초과하면
		// 초과한 데이터를 POP하도록 코드 수정.
		// 
		// 여기서 한가지 문제는 최대힙으로 만들면 최대값이 pop되어버려 데이터가 손상된다.
		// 그래서, 최소힙으로 수정
		if (n < q.size())
			q.pop();
	}

	// for (int i = 0; i < n - 1; i++)
	// 	q.pop();
	cout << q.top();
}