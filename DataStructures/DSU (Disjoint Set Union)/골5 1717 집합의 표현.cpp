// https://yuminlee2.medium.com/union-find-algorithm-ffa9cd7d2dba
// 최적화 시각화 자료

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> p(1000002, -1);

// path compression
int find(int x)
{
    if (p[x] < 0) return x; // -가 나오면 본인 x가 root node라는 뜻 !
    return p[x] = find(p[x]); // find(p[x])로 root를 대입 후 반환
}

// union by rank
bool union_(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false; // 이미 같은 union이면 x
        
    if (p[v] < p[u]) // 1. v의 rank가 더 클경우
        swap(u, v); // u를 더 rank가 작은부모로 만들기 위해 swap
    
    if (p[u] == p[v]) // 2. rank가 같다면 1 rank 증가
        p[u]--;
        
    p[v] = u; // v를 u의 자식으로
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    // unions n
    // test case m
    
    while (m--)
    {
        // 합집합 - 0 u v
        // union-find - 1 u v
        
        int t, u, v;
        cin >> t >> u >> v;
        
        if (t == 0)
            union_(u, v);
        else if (find(u) == find(v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}


