// https://yuminlee2.medium.com/union-find-algorithm-ffa9cd7d2dba 최적화 시각화 자료
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p(300002, -1);

// path compression
int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]); 
}

// union by rank
bool union_(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false; 
        
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
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n-2; i++)
    {
        int u, v;
        cin >> u >> v;
        union_(u, v); // 합집합 생성
    }
    
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (p[i] < 0)
            ans.push_back(i);
    
    for (int i = 0; i < ans.size()-1; i++)
        cout << ans[i] << ' ' << ans[i+1] << '\n'; 
}