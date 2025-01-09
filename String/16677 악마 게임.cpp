#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, g, maxScore = 0;
    string findStr, inputStr, answer;
    cin >> findStr;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> inputStr >> g;
        int score = 0;

        // 문자열에서 findStr이 등장하는 횟수를 세기
        size_t pos = inputStr.find(findStr, 0);
        while (pos != string::npos)
        {
            score += g;
            pos = inputStr.find(findStr, pos + findStr.length());
        }

        if (score > maxScore)
        {
            maxScore = score;
            answer = inputStr;
        }
    }

    if (maxScore > 0)
        cout << answer;
    else
        cout << "No Jam";

    return 0;
}
