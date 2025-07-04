#include <string>
#include <vector>
#include <unordered_map> 

using namespace std;

int solution(string s) 
{
    string answer = "";
    string cur_answer = "";
    unordered_map<string, string> nums = 
    {
        {"zero", "0"}, {"one", "1"}, {"two", "2"},
        {"three", "3"}, {"four", "4"}, {"five", "5"},
        {"six", "6"}, {"seven", "7"}, {"eight", "8"}, 
        {"nine", "9"}
    };

    size_t pos = 0;
    for (auto c : s)
    {
        // 1. 숫자면
        if (isdigit(c))
        {
            answer += c;
        }
        // 2. 문자면
        else
        {
            cur_answer += c;
            if (nums.count(cur_answer))
            {
                answer += nums[cur_answer];
                cur_answer = "";
            }
        }
    }

    return stoi(answer);
}