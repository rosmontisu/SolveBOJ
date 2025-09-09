#include <iostream>

using namespace std;

long fun(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(n == 2)
        return 1;
        
    //boj solve 용 보정
    else
        n--;
    
    long cache[n + 1];
    cache[0] = 1;
    cache[1] = 1;
    
    for (int i = 2; i < n+1; i++)
    {
        cache[i] = cache[i-1] + cache[i-2];
    }
    
    return cache[n];
}

int main(void)
{
    int n = 0;
    cin >> n;
    cout << fun(n);
    return 0;
}
