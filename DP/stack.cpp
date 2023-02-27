#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
vector 자료구조 새로 배웠음
자동으로 메모리가 할당되는 배열
stack 과 비슷한 구조

vector<T> [name];
ex) vector<int> vec(5, n);
>> n으로 초기화된 5개의 원소 벡터 선언

ex) vector<int> vec2(vec1);
>> vec2는 vec1 복사
*/



int main(void)
{
    stack<int> stk;
    vector<char> vec;

    int count = 1;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        // stack 1 부터 새로 입력 받은 수 x까지 psuh
        int x;
        cin >> x;
        while(count <= x)
        {
            stk.push(count);
            count++;
            vec.push_back( '+' );
        }

        // 최상위 스택이 x라면?
        // pop
        if(stk.top() == x)
        {
            stk.pop();
            vec.push_back( '-' );
        }    
        else // 실패한 경우
        {
            cout << "NO";
            return 0;
        }         
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << '\n'; // 시간 초과 해결 endl..
    } 
}
