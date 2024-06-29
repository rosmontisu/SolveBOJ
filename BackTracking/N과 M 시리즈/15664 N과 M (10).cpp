#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
vector<int> answer;
int n, m; 

void dfs(int depth, int cur)
{
    // base case
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    
    dfs(depth+1, cur);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    dfs(0, 0);
}
