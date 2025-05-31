#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define X first
#define Y second

// 1. 각 선분을 서로 ccw연산 처리
// 교차 조건 - L1, L2 가 있을때, ccw(L1, p) * ccw(L2, p) <= 0 
// --
// p = { a, b, c, d } 일때 L1 = { a, b }, L2 = { c, d } 로 정의할때
// ((ccw(a, b, c) * ccw(a, b, d)) <= 0) && ((ccw(c, d, a) * ccw(c, d, b)) <= 0) 
// == (ccw(L1, c) * ccw(L1, d) <= 0) && (ccw(L2, a) * ccw(L2, b) <= 0)
// 단, 반례가 존재
// 두 선분의 ccw판정이 모두 0인경우?
// - 선분이 모두 평행하고, 일직선 상에 놓여져 있는 경우


// 시간 복잡도는 O(n^2)인데, 잡다한 n연산이 더 들러붙어서 느릴텐데 n <= 3000에 2초라 충분히 될거같다
vector <pair<pair<int, int>, pair<int, int>>> lines;

vector<int> p(3002, -1);
vector<int> usize(3002, 1);

long long ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return (a.X * b.Y + b.X * c.Y + c.X * a.Y
        - a.Y * b.X - b.Y * c.X - c.Y * a.X);
}

bool isCross(pair<pair<int, int>, pair<int, int>> l1, pair<pair<int, int>, pair<int, int>> l2)
{
    pair<int, int> a = l1.first;
    pair<int, int> b = l1.second;
    pair<int, int> c = l2.first;
    pair<int, int> d = l2.second;

    // 점 4개가 모두 일직선 상에 놓여져 있는 경우 (선분이 한 직선위에 있을 때)
    if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0 && ccw(c, d, a) == 0 && ccw(c, d, b) == 0)
    {
        // 점들을 정렬 
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);


        // max(시작점들) <= min(끝점들) - 시작점이 끝점이랑 겹치거나 닿는 경우 
        if (max(a, c) <= min(b, d)) return true; // 1. 동일 직선 위에서 선분이 겹친다
        else return false; // 1-2. 동일 직선 위에 있지만, 겹치지 않는다
    }

    // 2-1. 선분이 교차한다
    if (ccw(a, b, c) * ccw(a, b, d) <= 0 && ccw(c, d, a) * ccw(c, d, b) <= 0) return true;
    // 2-2. 선분이 교차하지 않는다
    else return false;
}

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]); // path compression
}

// union by rank
bool union_(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false;

    if (p[v] < p[u])
        swap(u, v); // rank x
    if (p[u] == p[v])
        p[u]--; // rank + 1

    p[v] = u;
    usize[u] += usize[v]; // 이전 집합의 size를 가져감
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 예외처리 1
    if (n == 1)
    {
        cout << 1 << '\n' << 1;
        return 0;
    }

    // 선분 입력
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        lines.push_back({ {a, b}, {c, d} });
    }

    // 선분 확인 및 그룹 생성
    int cnt = n; // 초기 집합의 수는 n개
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (find(i) == find(j)) continue; // 이미 겹침
            if (isCross(lines[i], lines[j]))
            {
                // i-j번 선분 union
                // union 성공시 집합의 수가 1개 줄어듬
                if (union_(i, j)) cnt--;
            }
        }
    }

    // 출력
    cout << cnt << '\n';
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, usize[i]);
    cout << ans;
}