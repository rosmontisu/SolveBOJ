#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        // R 뒤집기
        // D 버리기 - 비어 있다면 에러

        string s; cin >> s;
        queue<char> q; // 명령어 큐
        for (char c : s)
            q.push(c);

        int n; cin >> n;
        string ss; cin >> ss;
        deque<int> dq;
        string num = "";
        for (char c : ss)
        {
            if (c >= '0' && c <= '9')
                num += c;
            else if (!num.empty())
            {
                dq.push_back(stoi(num));
                num = "";
            }
        }

        bool rev = false;
        while (!q.empty())
        {
            char cur = q.front(); q.pop();
            if (cur == 'R')
                rev = !rev;
            else
            {
                if (dq.size() == 0) 
                {
                    dq.push_back(-1);
                    break;
                }
                if (rev) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (dq.front() == -1)
            cout << "error" << '\n';
        else
        {
            cout << '[';
            while (dq.size() > 1)
            {
                if (rev) 
                {
                    cout << dq.back() << ',';
                    dq.pop_back();
                }
                else 
                {
                    cout << dq.front() << ',';
                    dq.pop_front();
                }
            }
            if (dq.size() == 1)
                cout << dq.front();
            cout << ']' << '\n';
        }
    }
}