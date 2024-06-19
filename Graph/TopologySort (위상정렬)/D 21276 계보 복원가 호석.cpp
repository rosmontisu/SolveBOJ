/*
D가 붙은건 푸는데 유독 오래걸렸던 문제들입니다.
-> 꼭 다시 풀어보기!

코드 전체 지우고 다시 짜고만 4번 넘게..
4 5시간 정도 걸린거 같네요

4. 부모-친자식 : 이 부분 해결이 어려워서 답안보고 힌트얻고 코드 수정했습니다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m;
string s1, s2;

string name[1002]; // 초기 이름 저장 
vector<int> adj[1002]; // 인접 리스트 그래프
map<string, int> nameToID; // 이름 -> 숫자 변환 맵
int indegree[1002]; // 자신을 향하는 vertex(indegree 저장)


vector<int> result[1002]; // 친 자식 저장요ㅇ

int main()
{
	// 1. 사람 이름 입력받기
	int n;
	cin >> n; // 사람의 수
	for (int i = 1; i <= n; i++)
		cin >> name[i];
	sort(name + 1, name + n + 1); // nameToID에 넣기전에 미리 정렬
	for (int i = 1; i <= n; i++)
		nameToID[name[i]] = i;


	// 2. 부모 자식 관계 그래프를 만들고, idegree 측정
	int m; // 기억하는 정보의 수
	string strC, strP; // 자식, 조상
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> strC >> strP;
		adj[nameToID[strP]].push_back(nameToID[strC]);
		indegree[nameToID[strC]]++;
	}


	// 3. 시조 찾기 및 수와 이름 출력 (indegree == 0)
	vector<int> rootsNums; // 시조 번호 저장 벡터
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			rootsNums.push_back(i);
	
	cout << rootsNums.size() << '\n';
	for (int n : rootsNums)
		cout << name[n] << ' ';
	cout << '\n';

	// 4. indegree 측정으로 부모-친자식 한정으로 위상정렬 및 정답 벡터 구현
	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end()); // 이걸 왜 정렬하지?
											// 여기서 연결이 끊어져도 어차피 indegree가 있어서 상관 없기는한데
											// 굳이 정렬이 필요한가?
											// -> 자식의 이름도 사전순으로 출력이 필요해서!
		for (int ch : adj[i])
		{
			if (indegree[ch] - indegree[i] == 1) // 친부모 - 자식 관계
				result[i].push_back(ch);

			//indegree[ch]--;
		}
	}

	// 5. 정답 벡터 양식에 맞춰 출력
	for (int i = 1; i <= n; i++)
	{
		cout << name[i] << ' ' << result[i].size() << ' ';
		if (result[i].size() > 0)
			for (int n : result[i])
				cout << name[n] << ' ';
		cout << '\n';
	}
}