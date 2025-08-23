#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// 손님이 가장 많이 적체될때 몇명인가?
int solution(vector<int> menu, vector<int> order, int k) 
{
    int answer = 1;  
    
    deque<int> dq;
    dq.push_back(menu[order[0]]); // 첫 손님 size 1
    for (int i = 1; i < order.size(); i++)
    {
        int kk = k;
        while (!dq.empty())
        {
            int now = dq.front(); dq.pop_front();
            
            if (now > kk)
            {
                dq.push_front(now-kk); 
                break;
            }
            else if (now < kk) kk -= now;
            else break;
        }
        
        dq.push_back(menu[order[i]]); 
        answer = max(answer, (int)dq.size()); 
    }
    
    return answer;
}