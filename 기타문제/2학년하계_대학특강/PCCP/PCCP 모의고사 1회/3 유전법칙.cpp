#include <string>
#include <vector>
using namespace std;

string recur(int n, int p)
{
    if (n == 0) return "Rr";
    if (n == 1)
    {
        if (p == 0) return "RR";
        else if (p == 1 || p == 2) return "Rr";
        else return "rr";
    }
    
    string s = recur(n-1, p/4);
    if (s == "RR") return "RR";
    else if (s == "rr") return "rr";
    else
    {
        if (p%4 == 0) return "RR";
        else if (p%4 == 3) return "rr";
        else return "Rr";
    }
}

vector<string> solution(vector<vector<int>> queries) 
{
    vector<string> answer;
    
    for (auto cur : queries)
        answer.push_back(recur(cur[0]-1, cur[1]-1));
    return answer;
}


// 1. RR -> RR
    // 2. rr -> rr
    // 3. Rr -> RR Rr Rr rr
    
    // bottom -> up 으로 dp만들면 되지 않나?
    // 자식이 4개씩 나오는 트리?
    
    // 자식의 정보가 부모의 유일성을 보장하지 않음
    // b->u 안됨
    
    // top down으로 해야됨
    
    // 부모가 Rr 이므로
    // 1 : RR -> 1234 5 9 ::: (Rr넘버링-1)x4+1
    // 2 3 : Rr -> 67 1011
    // 4 : rr -> 8 12 13141516

    // 즉 rank 가 r, 번호가 n일때
    // RR : [1][1] : 
    //      [2][1] [2][2] [2][3] [2][4] | [2][5] | [2][9]
    //      
    // ->   이전 rank Rx4는 확정,  // 2번의 자식은? 5 6 7 8
    // 
    // -> 5번 to 2번, 6번 to 3번... 8번 to 4번? :: /4
    // 그럼 몇번인지는 %4
    // ----- 
    // 층수 : n
    // 몇번 : p
    // 부모 : (n-1, parent_p)
    // 자식 : (n, p)
    // 내려갈때 p의 증가량 : 4^n (0-index 기준)
    // 자식 -> 부모 : (p-1)/4  == (0123 = 0번 / 4567 = 1번 / p = (p-1)/4번 )
    // 몇번째 자식? : (p-1)%4  == (0 1 2 3)
    // base case : n == 0 (Rr), n==1 (RR, Rr, Rr, rr)