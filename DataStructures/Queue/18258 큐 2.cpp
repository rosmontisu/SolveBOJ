#include <iostream>
#include <queue>
using namespace std; queue<int> Q;

void push(int x) {
	Q.push(x);
}
void pop() {
	if (Q.empty()) cout << -1 << '\n';
	else {
		cout << Q.front() << '\n';
		Q.pop();
	}
}
void size() {
	cout << Q.size() << '\n';
}
void empty() {
	cout << (Q.empty() ? 1 : 0) << '\n';
}
void front() {
	cout << (Q.empty() ? -1 : Q.front()) << '\n';
}
void back() {
	cout << (Q.empty() ? -1 : Q.back()) << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s;
	
	while (n--)
	{
		cin >> s;
		if (s == "push") {
			int push_n;  cin >> push_n;
			push(push_n);
		}
		else if (s == "pop") pop();
		else if (s == "size") size();
		else if (s == "empty") empty();
		else if (s == "front") front();
		else if (s == "back") back();
	}
}
