#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--)
	{
		multiset<int> ms;
		int k; cin >> k;
		while (k--)
		{
			// D 1	: 최댓값 삭제
			// D -1 : 최솟값 삭제
			// I n	: insert n
			char c; int num;
			cin >> c >> num;
			if (c == 'D' && ms.size() > 0 && num == 1) {
				multiset<int>::iterator itr = --ms.end();
				ms.erase(itr);
			}
			else if (c == 'D' && ms.size() > 0) {
				multiset<int>::iterator itr = ms.begin();
				ms.erase(itr);
			}
			else if (c == 'I') ms.insert(num);
		}

		if (ms.size() > 0)
		{
			auto it1 = ms.begin();
			auto it2 = --ms.end();
			cout << *it2 << ' ' << *it1 << '\n';
		}
		else cout << "EMPTY\n";
	}
}
