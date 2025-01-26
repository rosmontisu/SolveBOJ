#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
int a[1000001];
int ans[1000001];
int f[1000001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int input;
        cin >> input;
        a[i] = input;
        f[a[i]]++; // f(i)는 여기서 계산
    }

    /*
    - 현재 수의 등장 횟수보다 많이 등장한 수가 오른쪽에 있는가?

    - 수열의 왼쪽에 존재할수록 등장 횟수가 증가합니다.
    -- 가장 오른쪽 수부터 등장 횟수를 스택으로 카운트하면 자연스럽게 오름차순으로 찾을 수 있음
    --- 단조 스택으로 정리 가능

    - 이때, ans에 들어가야되는건 자신보다 등장 횟수가 큰 숫자
    -- 각 수의 등장 횟수를 기록하는 배열이 필요할듯
    --- f(n) 을 기록해야함 


    ---- 1/22 22:00 다시 생각 정리 -----
    * i : {1 ~ N} 입니다
    1. 수열 A[i]
    2. 각 수열의 정답 ans[i]
    3. i가 수열 A에서 등장한 횟수 F[i] ->> 등장 횟수는 입력 받을대 카운트? 
    4. greatest 탈락이 안된 i는 stk에 저장



    xxxxx
    조건을 잘못 생각했음
    - 숫자가 오른쪽에 있어야 함
    - '모든'수열에서 해당 수의 카운트가 더 높아야함
    -- 그냥 단순하게 모든 수의 카운트를 배열에 만들고..
    --- 스택에는 오른쪽 숫자부터 저장만 하면됨
    */


    for (int i = 1; i <= n; i++)
    {
        // 스택이 아직 남아 있음
            // 이때 스택은 오름차순으로 pop됨 f(1 2 3 ...)t
        // 현재 가장 높고 가까운 수의 f(a(stk)) < 현재수의 f(a(i))
        while (!stk.empty() && f[a[stk.top()]] < f[a[i]])
        {
            ans[stk.top()] = a[i]; 
            stk.pop();
        }

        stk.push(i);
    } 

   

    for (int i = 0; i < n; i++) 
        cout << ans[i] << ' ';

}