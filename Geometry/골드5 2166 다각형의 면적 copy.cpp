#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

long double solve(int i, int j) {
	long double a = v[0].first, b = v[0].second;
	long double c = v[i].first, d = v[i].second;
	long double e = v[j].first, f = v[j].second;

	return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	long double ans = 0;
	for (int i = 1; i < n - 1; i++) {
		ans += solve(i, i + 1);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans) << endl;
}