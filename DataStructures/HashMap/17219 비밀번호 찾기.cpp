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
	int n, m;
	cin >> n >> m;
	string url, password;
	map<string, string> map;

	for (int i = 0; i < n; i++)
	{
		cin >> url >> password;
		map[url] = password;
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> url;
		cout << map[url] << '\n';
	}
	return 0;
}
