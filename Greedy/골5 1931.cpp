#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    // 끝나는 시간이 같다면 시작 시간이 빠른 순으로 정렬
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second; // 오름차순 정렬
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;

        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), cmp);

    

    int oldEnd = v[0].second; // 현재 서치하는 막대의 끝 시간
    int newStart; // 새로 서치하는 막대의 시작 시간

    int answer = 1; // 넣을 수 있는 막대기의 개수는 최소 1개

    //int cursor = 0; // 커서를 0으로 설정 - 현재 서치하려는 막대의 인덱스

    for (int i = 1; i < n; i++)
    {
        newStart = v[i].first; 

        if (oldEnd <= newStart)
        {
            oldEnd = v[i].second;
            answer++;
        }
    }

    cout << answer << '\n';
}