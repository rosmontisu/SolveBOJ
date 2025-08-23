#include <iostream>
using namespace std;

int main()
{
    long long n; 
    cin >> n;

    /*
        정사각형 한변의 길이는 1입니다.
        고로, 정사각형의 둘레는 4입니다.

        왼쪽과 오른쪽은 n*2
        위쪽은 무조건 1입니다.
        아래쪽은 무조건 n입니다.
        위에 반쪽들은 0 - 1(0.5*2) - 2(0.5*4) ...
        n-1입니다.

        식을 정리하면
        1 + n + n*2 + n - 1
        = 4n
    */
   
   cout << 4 * n;
}