#include <string>
#include <vector>

using namespace std;
int count[300];

string solution(string input_string) 
{
    string answer = "";

    // 1. 문자가 여러번 나오는가?
    // 2. 여러번일때, 그룹이 2개 이상인가?
    // 3. 외톨이를 사전순(오름차순)으로 정렬하라
    // 단, 없다면 N

    // 예외처리
    if (input_string.length() == 1)
    {
        answer = "N";
        return answer; 
    }
   
    count[input_string[0]]++; // 0번 문자는 무조건 포함시키고, 1부터 루프돌린다
    for (int i = 1; i < input_string.length(); i++)
    {
        // 같은 문자 덩어리는 생략해도된다.
        if (input_string[i] == input_string[i-1]) continue;

        count[input_string[i]]++;   
    }

    for (int i = 'a'; i <= 'z'; i++)
    {
        if (count[i] > 1)
        {
            answer += (char)i;
        }
    }

    if (answer == "")
        return "N";
    else
        return answer;
}