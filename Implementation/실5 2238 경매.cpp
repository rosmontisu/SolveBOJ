#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, string> vec[100005];

int main()
{
    int u, n; cin >> u >> n;
    int cnt = 987654321;
    while (n--)
    {
        string name;
        int price; 
        cin >> name >> price;
        
        // 처음 나온 가격에만 이름 기록
        if (vec[price].first == 0) vec[price] = { vec[price].first+1, name };
        else vec[price].first++;
    }
    
    // cnt 중복으로 못찾는 경우 있음
    for (int i = 0; i <= u; i++)
        if (vec[i].first > 0)
            cnt = min(cnt, vec[i].first);
    
    for (int i = 0; i <= u; i++)
    {
        if (vec[i].first == cnt)
        {
            cout << vec[i].second << ' ' << i;
            break;
        }
    }
}