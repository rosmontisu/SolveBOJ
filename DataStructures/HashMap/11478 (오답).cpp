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
	string str;
	cin >> str;
	map<string, bool> map;
	int strCut = 0;
	int count = 0;
	
	// cabac
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < str.length() - i; j++)
		{
			// string.substr(a, b) -> string[a]부터 b만큼 자른다.
			if (map[str.substr(j, j + i)] == false)
			{
				map[str.substr(j, j + i)] = true;
				count++;
			}
		}
	}

	cout << count;
}
