#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    stack<char> stk;
    string str; cin >> str;
    
    int answer = 0; 
    stk.push(str[0]);
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            stk.push('(');
        }
        else if (str[i-1] == str[i])
        {
            stk.pop();
            answer++;   // 끝날때 1개 더 생김
        }
        else
        {
            stk.pop();
            answer += stk.size();
        }
    }
    
    cout << answer;
    return 0;
}
