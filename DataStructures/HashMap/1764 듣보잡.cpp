#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
// 단순 문자열 벡터나 배열을 만들고 정열 + 탐색 알고리즘으로 푸는것도 가능하나
// STL map()을 이용해서 풀어보았다.

int main()
{
	int n, m;
	cin >> n >> m;

	map<string, int> map;	// map<keyT, valueT> name;
	string str;
	vector<string> answer;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		map[str]++;
		//map에서 key가 str인 값의 value를 증가시킨다.
	}
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		map[str]++;
	}

	// iterator 사용한 구식 for문 형태
	// 반복문 데이터 접근 (first, second)
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		if (iter->second == 2)
			answer.push_back(iter->first);
	}

	cout << answer.size() << endl;
	sort(answer.begin(), answer.end());	// 문제에서 정답을 사전순으로 출력하라 했음
	

	// 범위 기반 for문 형태
	// for (Type element : list) 
	for (auto iter : answer)
	{
		cout << iter << endl;
	}
	return 0;
}