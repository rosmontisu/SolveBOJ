#include <iostream>

using namespace std;

int dp(int f, int r)
{
    /*
    
    2f  |1   4   10  20
    1f  |1   3   6   10
    0f  |1   2   3   4
    */
    int cache[f+1][r+1] = {};
    
    
    // 0층 인원 넣기
    for (int i = 1; i < r+1; i++)
    {
        cache[0][i] = i;
    }
    
    for(int i = 1; i < f+1; i++) // 1층부터 f층까지
    {
        for(int j = 1; j < r+1; j++) // 1호부터 r호까지
        {
            // 1층 아래에 인원을 1호부터 r호까지 넣어준다.넣어준다.
            for(int k = 1; k < j+1; k++)
            {
                cache[i][j] += cache[i-1][k];
            }
            
        }
    }
    
    return cache[f][r];
}

int main(void)
{
    int t, f, r;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> f;
        cin >> r;
        cout << dp(f, r) << endl;
    }
    return 0;
}
