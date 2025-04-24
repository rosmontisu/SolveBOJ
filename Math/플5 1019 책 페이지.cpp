/*
시간 초과
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[12] = {};
    int data[10][10]; // 초기화 값, 미리 연산해 둘예정
    int n;
    cin >> n;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            data[i][j] = 0;

    // 미리 (1,1) 부터 (9,9) 까지의 값을 구하기 
    for (int i = 1; i < 10; i++)
    {
        int temp = i;

        while (true)
        {
            data[i][temp % 10]++;
            if (temp / 10 == 0) break;
            temp /= 10;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int temp = i;

        while (true)
        {
            arr[temp % 10]++;
            if (temp / 10 == 0) break;
            temp /= 10;
        }
    }

    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';
}
*/

/*
핵심 아이디어는 0~n까지 모두 탐색해서 O(N)이 되는 시간복잡도를
각 자릿수에서만 연산함으로 O(LogN)으로 바꾸는것

접근
1의 자리, 10의 자리, 100의 자리, ... 처럼 N보다 작거나 같은 가장 큰 자리수까지 반복.
현재 자리수를 p라고 할때, (ex: 십의 자리는 p=10).=

각 자리수 p와 각 숫자 d (0~9)에 대해, 1부터 N까지의 숫자 중 p의 자리에 숫자 d가 몇 번 나오는지 계산
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 1부터 n까지 각 숫자가 몇 번 등장하는지 계산하는 함수
// 결과와 자리수 변수에 long long을 사용하여 오버플로우 방지
vector<long long> count_digits(int n) 
{
    vector<long long> ans(10, 0); // 결과를 저장할 배열 (long long 타입)
    long long power_of_10 = 1;    // 현재 처리할 자리수 (1, 10, 100, ...) (long long 타입)

    // 현재 자리수가 n의 범위 내에 있는 동안 반복
    while (n >= power_of_10) 
    {
        // --- 현재 자리수 'power_of_10'에 대한 계산 ---
        // 다음 자리수 (블록 크기 계산용)
        long long next_power_of_10 = power_of_10 * 10;
        // n 앞에 있는 완전한 블록의 개수
        long long prefix = n / next_power_of_10;
        // n의 현재 자리수에 있는 숫자
        long long current_digit = (n / power_of_10) % 10;
        // 현재 자리수가 current_digit일 때 나타나는 횟수 (N까지 고려)
        long long suffix_count = (n % power_of_10) + 1;

        // --- 각 숫자 d (0~9)에 대해 계산 ---
        for (int d = 0; d < 10; ++d) 
        {
            // 1. 완전한 블록에서의 기여 (prefix * power_of_10)
            // 각 완전한 블록은 현재 자리에서 숫자 'd'를 'power_of_10'번 포함
            ans[d] += prefix * power_of_10;

            // 2. 현재 블록 (N이 포함된 불완전 블록)에서의 기여
            if (current_digit > d) 
                // n의 현재 자리 숫자가 d보다 크면, d는 이 블록에서 'power_of_10'번 완전히 나타남
                ans[d] += power_of_10;
            else if (current_digit == d) 
                // n의 현재 자리 숫자가 d와 같으면, d는 이 블록에서 'suffix_count'번 나타남
                ans[d] += suffix_count;
            // current_digit < d 이면, d는 이 블록의 남은 부분에서 현재 자리에 나타나지 않음 (0 더함)
        }

        // --- 선행 0 제거 ---
        // 위 로직은 숫자가 0으로 채워져 있다고 가정하고 계산함 (예: 000~n)
        // 이 과정에서 불필요한 선행 0들이 ans[0]에 더해짐
        // 각 자리수 'power_of_10'마다 'power_of_10'개의 선행 0이 더해졌으므로 빼줌
        ans[0] -= power_of_10;

        // --- 다음 반복 준비 ---
        // power_of_10에 10을 곱하기 전에 오버플로우 가능성 확인
        // (N이 매우 클 경우 중요, long long은 충분한 범위를 제공)
        if (power_of_10 > n / 10) { // power_of_10 * 10 > n 과 같음 (오버플로우 방지 형태)
            break; // 다음 자리수는 n보다 커지므로 중단
        }
        // long long 자체의 오버플로우 방지
        if (power_of_10 > __LONG_LONG_MAX__ / 10) 
            break; // 10을 곱하면 long long 범위를 넘어설 경우 중단

        power_of_10 *= 10; // 다음 자리수로 이동
        // 혹시 모를 오버플로우 발생 시 (위에서 방지했지만) 0이 되면 무한루프 방지
        if (power_of_10 == 0) break;
    }

    return ans;
}

int main() 
{
    // 입출력 속도 향상
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 최적화된 함수를 사용하여 결과 계산
    vector<long long> result = count_digits(n);

    // 결과 출력
    for (int i = 0; i < 10; ++i) 
        cout << result[i] << (i == 9 ? "" : " "); // 마지막에는 공백 없이 출력

    return 0;
}