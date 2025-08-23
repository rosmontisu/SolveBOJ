#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int isUsed[200];

string solution(string input_string) 
{
    string answer = "";
    
    // 2번 이상 등장하는데
    // 2개 이상 독립? - 뭉치지 않음
    
    if (input_string.length() == 1)
        return "N";
    
    isUsed[input_string[0]] = 1; // 초기값
    for (int i = 1; i < input_string.length(); i++)
    {
        if (input_string[i] == input_string[i-1]) continue;
        
        isUsed[input_string[i]]++;
    }
    
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (isUsed[i] >= 2)
        {
            answer += i;
        }
    }
    
    
    if (answer == "") return "N";
    
    return answer;
}