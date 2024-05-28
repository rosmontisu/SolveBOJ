#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int length, c;
vector<char> chars;
vector<char> answer; 

// *개선점*
// if문을 불리안 형태의 함수로 추출
bool aeiou(char t) 
{
    return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u'; 
}
void dfs(int depth, int cur, int vowel, int consonant)
{
    if (depth == length)
    {
        if (vowel >= 1 && consonant >= 2)
        {
            for (char ch : answer)
                cout << ch;
            cout << '\n';
        }
        return;
    }
    for (int i = cur; i < c; i++)
    {
        answer.push_back(chars[i]);

        if (aeiou(chars[i])) dfs(depth + 1, i + 1, vowel + 1, consonant);
        else dfs(depth + 1, i + 1, vowel, consonant + 1);

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