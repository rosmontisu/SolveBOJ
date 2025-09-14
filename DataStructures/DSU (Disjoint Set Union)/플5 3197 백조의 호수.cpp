#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p(100002, -1);

int find(int x)
{
    if (p[x] < 0)
        return x;

    return p[x] = find(p[x]); 
}


bool union_(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v) return false; 
        
    if (p[u] > p[v]) swap(u, v); 
    if (p[u] == p[v]) p[u]--;
        
    p[v] = u; 
    
    return true;
}

char map[1505][1505];
int main()
{
    // . 물
    // X 빙판
    // L 백조

    int r, c;
    cin >> r >> c;

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> map[i][j];

    
    
    
    
}