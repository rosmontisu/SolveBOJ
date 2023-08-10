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
	int num;
	map<int, bool> map;
	vector<int> vec;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &num);
		map[num] = true;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		scanf(" %d", &num);
		if (map[num])
			vec.push_back(1);
		else
			vec.push_back(0);
	}

	for (int i = 0; i < m; i++)
	{
		// cout은 str만 출력되던?가
		cout << to_string(vec[i]) + " ";
	}

	return 0;

}
