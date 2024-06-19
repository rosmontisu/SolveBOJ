#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

int indegree[1001]; // 각 정점의 indegree 저장배열
vector<string> adj[1001]; // my graph
vector<string> result[1001];

map<string, int> nameToID;
// 각 문자열(이름)을 숫자로 치환해서 풀면 좀 더 깔끔할거 같네요?

int main()
{
    // 1. 이름 입력 부분
    int k;
    cin >> k;
    string str;
    for (int i = 1; i <= k; i++)
    {
        cin >> str;
        adj[i].push_back(str);

        nameToID.insert(make_pair(str, i));// 문자열에 대응되는 번호를 붙여줍시다.

        
    }

    // 2. 그래프 입력 부분
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string str1, str2;
        cin >> str1 >> str2; // str2조상 -> str1자식 형태의 그래프

        // 각 이름의 int형 value값으로 변환해줍시다
        // 지금처럼 자식:조상 입력을 받을때 이런식으로 그래프를 만들면
        //  hoseok sangdo
        // daeil sangdo 
        // (hoseok daeil)

        // 위 처럼 입력 받았을때 더 상위 조상의 구분이 없이 모두 바로 부모로 연결되어버린다.
        // 부모1 - 부모2 - 자식 형태를 구분할 수 있게 개선이 필요
        // indegree로 측정하면?
        
        // 입력 부분 다시 구현해야될듯 ㄴㅁㅇㄻㄴㅇㄹㅇㅁㄴㄹㄴㅇㅁㄹ
        adj[nameToID.at(str2)].push_back(str1); 
        indegree[nameToID.at(str1)]++;
    }

    // i guess it is just a korean font issue?
    // 주석 주글주글한건 그냥 한글 폰트가 문제인거 같은데?

    // 3. 위상 정렬 알고리즘
    queue<int> q;
    for (int i = 1; i <= k; i++)
    {
        if (indegree[i] == 0)
            q.push(i);

        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            for (auto nxt : adj[cur])
            {
                result[cur].push_back(nxt); // 새롭게 위상 정렬된 그래프 생성
                
                indegree[nameToID[nxt]]--;
                if (indegree[nameToID[nxt]] == 0)
                    q.push(nameToID[nxt]);
            }
        }
    }

    // 4. 출력
    for (int i = 1; i <= k; i++)
    {
        for (auto s : result[i])
        {
            cout << s << ' ';
        }
        cout << '\n';
    }
}