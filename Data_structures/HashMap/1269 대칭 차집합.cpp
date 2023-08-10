#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int num;
	map<int, bool> map1;
	map<int, bool> map2;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		map1[num] = true;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> num;

		// 차집합 구하기
		if (map1[num])
			map1[num] = false;
		else
			map2[num] = true;
	}

	int count = 0;
	for (auto iter : map1)
		if (iter.second == true)
			count++;
	for (auto iter : map2)
		if (iter.second == true)
			count++;

	cout << to_string(count);
	return 0;
}
