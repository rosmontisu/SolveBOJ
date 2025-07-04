#include <string>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer;   
    
    // 유저 인덱싱 번호 만들어주기
    map<string, int> user_to_idx;
    int n = id_list.size();
    for (int i = 0; i < n; i++)
    {
        user_to_idx[id_list[i]] = i; 
    }
    
    // 신고 관계도 행렬 생성 (단, 중복 x, 그냥 1 넣으면 댈덧)
    // report -> reported
    int report_matrix[1005][1005] = {0};
    for (string r : report)
    {
        stringstream ss(r);
        string reporter_str, reported_str;
        ss >> reporter_str >> reported_str;
        
        int reporter_idx = user_to_idx[reporter_str];
        int reported_idx = user_to_idx[reported_str];
        
        report_matrix[reporter_idx][reported_idx] = 1;
    }
    
    // 신고 당한 횟수 계산
    int count[1005] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count[i] += report_matrix[j][i];
        }
    }
    
    // 각 유저 메일 수 계산
    // 신고를 한 유저가 메일을 받음.
    // 신고 당한 유저가 2번 이상 신고를 받았을때
    for (int i = 0; i < n; i++)
    {
        int mail_count = 0; 
        for (int j = 0; j < n; j++)
        {   
            if (report_matrix[i][j] > 0) // 신고한 유저가 
                if (count[j] >= k) mail_count++; // k번 이상 신고당했으면, 메일 1 증가
        }
        answer.push_back(mail_count);
    }   

    return answer;
}