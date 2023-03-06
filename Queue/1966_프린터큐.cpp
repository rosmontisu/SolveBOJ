#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
pair queue
sort in c++ 등..
생소한 문법에서 배운게 많았던 문제
*/

void solve()
{
    vector<int> vec;
    queue<pair<int, int>> q;
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
        // 원하는 자료에 pair로 1 붙이기
        if (i == m){
            q.push({temp, 1});
        }
        else{
            q.push({temp, 0});
        }
    }

    //sort(strat, end, compare)
    sort(vec.begin(), vec.end());


    /*
    위의 과정으로 vec은 검사해야 하는 중요도를 순서대로 가지고 있으며,
    pair queue는 필요한 수라면 1, 아니라면 0으로 pair되어있다.
    */

    int answer = 0;
    while(1)
    {
        if (vec.back() == q.front().first){     // vec의 중요도 == queue의 중요도
           if (q.front().second == 1){          // 현재 찾고 있는 숫자라면?
               answer++;
               break;
            }
        else {                                
           vec.pop_back();                  // 찾고 있는 숫자가 아니므로 전부 삭제
           q.pop();
           answer++;
        }
    } 
        else {
        // 처음 보는 문법
        q.push({q.front().first, q.front().second});
        q.pop();
        }
    }
    cout << answer << endl;
}

int main(void)
{
    int t;
    cin >> t;
    while(t > 0)
    {
        solve();
        t--;
    }
    return 0;
}
