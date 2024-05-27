#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
1 : a, e, i, o, u
2 : 자음(bcdfghjklmnpqrstvwxyz)
*/

int length, c;
vector<char> chars;
vector<char> answer; 
bool isUsed[100];

// 깊이, 탐색방향, 모음, 자음
void dfs(int depth, int cur, int vowel, int consonant)
{
    if (depth == length)
    {
        if (vowel < 1 && consonant < 2)
            return;

        for (int i = 0; i < length; i++)
            cout << answer[i];
        cout << '\n';
        return;
    }

    for (int i = cur; i < c; i++)
    {
        if ((chars[i] == 'a' || chars[i] == 'e' ||chars[i] == 'i' ||chars[i] == 'o' ||chars[i] == 'u'))
        {
            if (isUsed[i]) continue;
            isUsed[i] = true;
            answer.push_back(chars[i]); vowel++;

            dfs(depth + 1, i, vowel, consonant);

            answer.pop_back(); vowel--;       
            isUsed[i] = false;

        }
        else
        {
            if (isUsed[i]) continue;
            isUsed[i] = true;
            answer.push_back(chars[i]); consonant++;

            dfs(depth + 1, i, vowel, consonant);

            answer.pop_back(); consonant--;
            isUsed[i] = false;
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> length >> c;
    for (int i = 0; i < c; i++)
    {
        char input; cin >> input;
        chars.push_back(input);
    }

    sort(chars.begin(), chars.end());
    dfs(0, 0, 0, 0);

    return 0;
}