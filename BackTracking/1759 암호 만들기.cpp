#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int length, c;
vector<char> chars;
vector<char> answer; 

// 깊이, 탐색방향, 모음, 자음
void dfs(int depth, int cur, int vowel, int consonant)
{
    if (depth == length)
    {
        // 조건을 명시하고, 실행하는게 더 좋습니다.
        // 조건 미충족시 return/break 는 가독성이 떨어집니다.
        if (vowel >= 1 && consonant >= 2)
        {
            for (char ch : answer)
                cout << ch;
            cout << '\n';
        }
        return;
    }

    // isUsed[]는 불필요합니다.
    for (int i = cur; i < c; i++)
    {
        answer.push_back(chars[i]);
        // 자음의 경우와, 모음의 경우에 다르게 처리
        if (chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u')
            dfs(depth + 1, i + 1, vowel + 1, consonant);
        else
            dfs(depth + 1, i + 1, vowel, consonant + 1);
        // dfs() 호출시에 들어가는 변수의 값은
        // depth의 변화에 따라 알아서 감소하므로, 다시 줄여줄 필요가 없습니다.
        // 전역 변수의 형태로 남아있는 vector와 같은 친구들만 직접 증감 처리를 해야되는것입니다.
        answer.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> length >> c;
    chars.resize(c); // 벡터 크기 초기화
    for (int i = 0; i < c; i++) 
        cin >> chars[i];

    sort(chars.begin(), chars.end());
    dfs(0, 0, 0, 0);
    return 0;
}