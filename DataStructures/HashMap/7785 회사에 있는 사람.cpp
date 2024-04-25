#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int t;
	map<string, bool> map;
	string name, commuting;
	vector<string> vec;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> name >> commuting;
		if (commuting == "enter")
			map[name] = true;
		else
			map[name] = false;
	}

	for (auto iter : map)
	{
		if (iter.second)
			vec.push_back(iter.first);
	}

	sort(vec.rbegin(), vec.rend());
	for (auto iter : vec)
	{
		cout << iter << '\n';
		// endl 쓰면 시간 초과 발생
	}

	return 0;
}
