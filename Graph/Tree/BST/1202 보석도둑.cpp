#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

multiset<int> bag; 
pair<int, int> jam[300001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int jamNum, bagNum;
	cin >> jamNum >> bagNum;

	for (int i = 0; i < jamNum; i++)
		cin >> jam[i].second >> jam[i].first; 
	// key를 value로 잡아야 검색이 가능하니까
	// cin >> 무게 >> 가치
	sort(jam, jam + jamNum);

	for (int i = 0; i < bagNum; i++)
	{
		int c;
		cin >> c; 
		bag.insert(c);
	}

	long long ans = 0;

	// 고가치부터 담아야 하므로 역순 루프
	for (int i = jamNum - 1; i >= 0; i--)
	{
		int m, v;
		m = jam[i].second;
		v = jam[i].first;

		auto it = bag.lower_bound(m);
		if (it == bag.end())
			continue;
		ans += v;
		bag.erase(it);
	}
	cout << ans;
	return 0;
}
