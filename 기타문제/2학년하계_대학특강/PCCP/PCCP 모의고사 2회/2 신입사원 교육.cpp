#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> ability, int number) 
{
    int answer = 0;
    /*
    매번 가장 작은 숫자 2개를 고르면됨
    -> pq
    */
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto n : ability)
    {
        pq.push(n);
        answer += n;
    }
    
    for (int i = 0; i < number; i++)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int sum = a + b;
        
        answer = (answer - a - b + sum + sum);
        pq.push(sum);
        pq.push(sum);
    }
    
    return answer;
}