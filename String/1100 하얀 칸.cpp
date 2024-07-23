#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int answer = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> s;

        if (i % 2 == 0) for (int j = 0; j < 8; j+2) if (s[j] == 'F') answer++;
        else for (int j = 1; j < 8; j+2) if (s[j] == 'F') answer++;
    }

    cout << answer;
}