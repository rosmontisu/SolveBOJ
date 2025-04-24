#include <iostream>
using namespace std;

int parent[1002];
int sz[1002];

// 집합의 루트 노드 찾기
int find(int x) 
{
    if (parent[x] == x) return x; // 같음
    return parent[x] = find(parent[x]); // 경로압축 (계속 깊어지는 트리를 평평하게 같은 층으로 올리는 작업)
}

// 두 집합이 같은 집합이 아니라면 병합
void union_(int a, int b) 
{
    a = find(a);
    b = find(b);
    if (a == b) return; // 이미 a와 b가 같은 집합 (부모가 같다)

    if (sz[a] < sz[b]) swap(a, b); // 더 작은 집합을 큰 집합에 병합
    parent[b] = a; // b의 부모를 a로 (a집합에 병합하므로)
    sz[a] += sz[b]; // a집합의 크기를 b집합 크기만큼 추가
}

int main() 
{
    int n, p;
    cin >> n >> p;
    
    for (int i = 1; i <= n; ++i) 
    {
        parent[i] = i;
        sz[i] = 1;
    }
    
    while (p--) 
    {
        int v, u;
        cin >> v >> u;
        union_(v, u);
    }
    
    int root = find(1);
    cout << sz[root] - 1;
    
    return 0;
}