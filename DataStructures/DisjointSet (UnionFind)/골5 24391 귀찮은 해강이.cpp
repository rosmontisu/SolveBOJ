// https://yuminlee2.medium.com/union-find-algorithm-ffa9cd7d2dba
// 최적화 시각화 자료

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> p(100002, -1);


int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]); // path compression
}


bool union_(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false; 
        
    // union by rank
    if (p[v] < p[u]) 
        swap(u, v); 
    if (p[u] == p[v]) 
        p[u]--;
        
    p[v] = u; 
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m; // 강의 수, 건물 수

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        union_(u, v); // 일단 집합만들고
    }


    // 1번 시간표를 cur로 빼서 비교연산을 같이하기
    int ans = 0;
    int cur;
    cin >> cur; 
    cur = find(cur); // 1. cur의 root를 찾아주지 않았기 때문에..

    for (int i = 1; i < n; i++)
    {
        int nx; 
        cin >> nx;
        nx = find(nx); 
        if (nx != cur) // 2. 여기서 쌩 cur와 root nx를 비교해서 문제가 발생했다.
        {
            ans++;
            cur = nx; 
        }
    }

    cout << ans;
    return 0;
}