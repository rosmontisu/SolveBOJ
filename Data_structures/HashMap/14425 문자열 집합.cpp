#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
// 중복 데이터 허용 x
// key가 유사하면 해시 충돌로 성능 저하 
// map - 이진탐색
// unordered_map - 해쉬테이블
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	string str;
	unordered_map<string, bool> map;
	
	//vector<string> vec;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		map[str] = true;
	}

	int count = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (map[str])
		{
			count++;
			// map[str] = false;
		}
	}

	cout << count;
	return 0;
}