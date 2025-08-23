#include <string>
#include <vector>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector<int> solution(string command) 
{
    vector<int> answer;
    int x = 0;
    int y = 0;
    int dir = 0;
    
    for (char c : command)
    {
        if (c == 'R')
            dir = (dir+1) % 4;
        else if (c == 'L')
            dir = (dir > 0 ? dir - 1 : 3);
        else if (c == 'G')
        {
            x += dx[dir];
            y += dy[dir];
        }
        else if (c == 'B')
        {
            x -= dx[dir];
            y -= dy[dir];
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}