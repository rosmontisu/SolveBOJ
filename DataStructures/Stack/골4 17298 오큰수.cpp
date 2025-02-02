// 처음 접근법

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> monotonic_stk;
int a[1000000];
int ans[1000000];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // 수열이 주어지고
    // 오른쪽에 있고, 더 큰수 찾기
    // 스택으로 하나하나 꺼내면서 찾으면 될듯

    // * 이거 스택 역순이네요?
    // 그냥 큐로 하면되겠다
    // -> 시간초과..

    // 큐로 하면 O(n^2)
    // Monotonic Stack (단조 스택) 이라는 개념이 필요
    /*
    1. 수열의 마지막 숫자에서 처음까지 역순으로 탐색 시작 (n -> 0)
    2. 현재 수와  스택의 top을 비교
        - 이때 top이 현재 수보다 크지 않다면 스택에서 제거
        -- 단조 감소 형태 유지
    3. 스택의 top을 정답 배열에 저장, 스택이 비었다면 -1 저장
    4. 현재 수를 단조 스택에 추가
    */

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a[i] = input;
    }


    // 마지막 수부터 시작 
    for (int i = n - 1; i >= 0; i--) 
    {
        // 현재 수보다 작은 수를 스택에서 제거
        // (마지막 수부터 왼쪽으로 진행하는데 현재 stk.top이 현재 수보다 크거나 같은 경우)
        // 가장 큰 값은 탈락
        while (!monotonic_stk.empty() && monotonic_stk.top() <= a[i]) 
            monotonic_stk.pop(); // 단조 스택에서 팝

        // 단조 스택이 비었다면 현재 수보다 오른쪽에 더 큰 수가 없다는 뜻
        // -1을 정답 배열에 저장
        if (monotonic_stk.empty())
            ans[i] = -1;
        else
            ans[i] = monotonic_stk.top(); // 단조 스택의 top을 정답 배열에 저장
        monotonic_stk.push(a[i]);
    }


    for (int i = 0; i < n; i++) 
        cout << ans[i] << ' ';

}