#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) 
{
    return a.first > b.first; // 내림차순
}

int main() 
{
    vector<pair<int, int>> v;

    for (int i = 0; i < 8; i++) 
    {
        int tmp;
        cin >> tmp;
        v.push_back({ tmp, i });
    }

    sort(v.begin(), v.end(), compare);

    int sum = 0;
    vector<int> ans;

    for (int i = 0; i < 5; i++) 
    {
        sum += v[i].first;
        ans.push_back(v[i].second + 1); // 1based 배열이 되도록 보정
    }

    sort(ans.begin(), ans.end());

    cout << sum << '\n';
    for (int n : ans)
        cout << n << ' ';
}