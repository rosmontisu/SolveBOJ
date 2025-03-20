#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string answer = "";
    for (int j = 0; j < 26; j++)
    {
        for (int i = 0; i < s.length(); i++)
        {
            answer += (s[i] - j) >= 'A' ? s[i] - j : 'Z' - ('A' - (s[i] - j)) + 1;
        }
        cout << answer;
        answer = "";
        cout << '\n';
    }
}
