#include <iostream>
#include <math.h>
using namespace std;

int ans(int a)
{
    // a^2 + b^2 = c^2
    // c가 자연수로 나오는 b의 개수 cnt
    int cnt = 0;
    
    // 1. a의 (자연수인)약수 범위 유도
    /* 
    a^2 = c^2 - b^2
    a^2 = (c+b)(c-b) = LK
    
    (c+b) = L
    (c-b) = K
    
    L > K
    LK > KK
    
    a^2 > K^2
    a > K
    a > c-b
    
    정리하면
    K == (c-b) 는 항상 a보다 1이상 작다
    */
    
    // 2. b 구하기
    /*
    L = K + 2b
    a^2 = K(K + 2b)
    (a^2/K - K) / 2 = b
    */
    
    for (int k = 1; k < a; k++)
    {
        if ((pow(a, 2)/k-k) / 2 > a) cnt++;
    }
    
    return cnt;
}

int main()
{
    while (true)
    {
        int a;
        cin >> a;
        if (a == 0) return 0;
        else cout << ans(a) << '\n';
    }
}