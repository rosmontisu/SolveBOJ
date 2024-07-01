#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // 선택 정렬 구현
    for (int i = 0; i < s.length(); i++)
    {
        int tmp = i;
        for (int cur = i + 1; cur < s.length(); cur++)
        {
            if (s[tmp] < s[cur])
                tmp = cur;
        }
        swap(s[i], s[tmp]);
    }

    cout << s;
}