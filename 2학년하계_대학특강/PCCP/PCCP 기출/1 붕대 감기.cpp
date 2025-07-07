 #include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int answer = 0;
    
    // t 시전시간
    // x 초당 회복량
    // y 추가 회복량
    // health 최대체력
    // h 현재 체력
    
    // atk 0 공격 시간
    // atk 1 피해량
    
    // 공격 받는 턴은 회복 x
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    
    int h = health;
    int cnt = 0;
    
    int atk_cnt = 0;
    int atkt = attacks[atk_cnt][0];
    int atk = attacks[atk_cnt][1];
    
    // 0시간부터 마지막 공격 시간까지 루프 돌림
    for (int i = 1; i <= attacks[attacks.size()-1][0]; i++)
    {
        // 예외 : 공격처리
        if (atkt == i)
        {
            h -= atk;
            cnt = 0; // 공격당하면 cnt초기화 
            atk_cnt++;
            if (atk_cnt < attacks.size()) 
            {
                atkt = attacks[atk_cnt][0];
                atk = attacks[atk_cnt][1];
            }
            
            
            // 사망 처리
            if (h <= 0) return -1;
                
            continue;
        }
        
        cnt++;
        if (h < health) 
            h += x;
        if (h > health)
            h = health;
        
        if (cnt == t)
        {
            h += y;
            if (h > health) h = health;
            cnt = 0;
        }
    }
    
    return h;
}