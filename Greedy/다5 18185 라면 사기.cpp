/*
1. 처음 생각하던 top을 찾는 방식
-> 첫번째 top을 잡고 지우는것까지는 ok 
but) 이후에 계속 top을 찾는 과정에서 비용이 든다

2. 4개씩 묶어서 생각하는 방식
-> A B C 0 이 경우에 중앙이 뾰족하면 문제가 생긴다? 
라는 반례를 쓰레기님 로직 보고 알았는데 굳이 0이 필요한가?
```
if((min({arr[i+1],arr[i+2],arr[i+3]}) != 0) && (arr[i] < arr[i+1]) &&(arr[i+2] < arr[i+1]))
        {
            arr_min = (arr[i] < (arr[i+1] - arr[i+2]))? arr[i]:(arr[i+1] - arr[i+2]);
            arr[i] -= arr_min;
            arr[i+1] -= arr_min;
            coin += 5 * arr_min;
        }
```

3. 3개씩 묶기 
-> 
    코드가 좀 더러웠지만 3개로 묶어도 문제 없을거 같아서 수정 후 테스트 케이스 돌려보는데
    vs code CPH JUDGE 에서 이상하게 
    3
    101
    -----------
    5
    1 1 1 0 2
    -------------
    위 2개 테스트케이스에서 계속 오류 발생

    심지어 반환값이 4??라는 이상한 값이 나옴 
    ----->>>> cph 버그였던걸로..
*/


// 4개식 묶어서 뾰족한거 있을때 2개씩 지우면 댐
// A B C 0 && B > C
// 3개씩 깎으면 손해봄 -> 나중에 뾰족한 B를 1번씩 깎아야대서 -> 고로 양쪽에서 가운데를 함께 깎아야댐

// 중앙이 뾰족한 경우를 제외하면 3개씩 지웠을때 1개가 고립되지 않음
// --> 직접 그림으로 깎아보면 되긴하는데.. 이걸 수학적으로 설명을 못하겠음..

// 로직에서 항상 앞을 기준으로 깎는 이유?
// --> 어차피 i++ 되면서 남은 부분을 기준으로 다시 3개씩 묶어서 찾을거라 상관 없음

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, answer = 0;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            // 뾰족한 모양? : 양쪽에서 함께 중앙 뾰족을 지워야댐
            if (v[i + 1] > v[i + 2])
            {
                // 2번 3번의 차이가 1번보다 작으면?
                // --> 뾰족한 부분을 3번과 같아질때까지 깎음
                // --> 2번3번을 똑같이 평평하게 만들 수 있음
                int minNum = min(v[i], (v[i + 1] - v[i + 2]));
                v[i] -= minNum;
                v[i + 1] -= minNum;
                answer += minNum * 5; // 누구 하나가 0이 될때까지 2개씩 깎음

                minNum = min(min(v[i], v[i + 1]), v[i + 2]); // min 2개씩만됨
                v[i] -= minNum;
                v[i + 1] -= minNum;
                v[i + 2] -= minNum;
                answer += minNum * 7; // 누구 하나가 0이 될때까지 3개씩 깎음
            }

            // 평범한 상태
            else
            {
                // 평범하게 누구 하나가 0이 될때까지 깎으면 됨
                int minNum = min(min(v[i], v[i + 1]), v[i + 2]);
                v[i] -= minNum;
                v[i + 1] -= minNum;
                v[i + 2] -= minNum;
                answer += minNum * 7; // 누구 하나가 0이 될때까지 3개씩 깎음

                minNum = min(v[i], v[i + 1]);
                v[i] -= minNum;
                v[i + 1] -= minNum;
                answer += minNum * 5; // 누구 하나가 0이 될때까지 2개씩 깎음
            }

            answer += v[i] * 3;
            v[i] = 0;
        }
    }

    cout << answer << '\n';
}

