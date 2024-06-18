#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

int indegree[1001]; // 각 정점의 indegree 저장배열
vector<string> adj[1001]; // my graph
vector<int> result;

map<string, int> nameMap;
// 각 문자열(이름)을 숫자로 치환해서 풀면 좀 더 깔끔할거 같네요?

int main()
{
    int k;
    string str;
    for (int i = 1; i <= k; i++)
    {
        cin >> str;
        adj[i].push_back(str);

        nameMap.insert(make_pair(str, i));// 문자열에 대응되는 번호를 붙여줍시다.

        
    }

    int m;
    for (int i = 1; i <= m; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;

        adj[nameMap[str1]].push_back(nameMap[str2]);

    }
}