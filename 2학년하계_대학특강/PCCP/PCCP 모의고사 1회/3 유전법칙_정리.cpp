#include <string>
#include <vector>
using namespace std;

string recur(int n, int p)
{
    if (n == 0) return "Rr"; // Base case
    
    string s = recur(n-1, p/4);
    
    if (s != "Rr") return s; // RR rr 이면 부모 따라가도록 개선
    
    // Rr인 경우 p로 판단
    if (p%4 == 0) return "RR";
    if (p%4 == 3) return "rr";
    return "Rr";
}

vector<string> solution(vector<vector<int>> queries) 
{
    vector<string> answer;
    
    for (auto cur : queries)
        answer.push_back(recur(cur[0]-1, cur[1]-1));
    return answer;
}