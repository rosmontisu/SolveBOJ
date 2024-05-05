#include <iostream>
using namespace std;

/*
입력받은 수를 n이라고 할때 (n의 크기는 32bit)
n의 2의보수를 m이라고 하자.

0bn 과 0bm 를 1bit부터 32bit까지 |= (or) 연산 후 그 수를 출력하면된다.

tmp1[i] = n &= (1 << i);
tmp2[i] = m &= (1 << i);
*/
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n;
    m = ~n;
    m += 1;

    int result = 0;
    for (int i = 0; i < 32; i++)
        if ((n & (1 << i)) != (m & (1 << i))) result++;

    cout << result;
    return 0;
}