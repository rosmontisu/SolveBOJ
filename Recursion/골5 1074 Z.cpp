// 25/08/31 스터디용
// 4진 트리로 구조화해서 그림판설명하기

#include <iostream>
using namespace std;

int func(int n, int r, int c) 
{
    // 1. base case - 1x1이면 무조건 첫 번째 (0)
	if (n == 0) return 0;
    
    // 2. 분할 - 변 길이 절반으로 나누기 2^(n-1)
	int half = 1 << (n - 1); 
    
    // 3. 정복(결합)
	if (r < half && c < half) 
        return func(n - 1, r, c); // 좌상귀, 바로 n-1 다음 재귀 호출
	if (r < half && c >= half) 
        return (half * half) + func(n - 1, r, c - half); // 좌상귀 칸 더함(half*half)
	if (r >= half && c < half) 
        return (half * half * 2) + func(n - 1, r - half, c); // 좌상귀+우상귀 칸 더함 (half*half) * 2
	if (r >= half && c >= half) 
        return (half * half * 3) + func(n - 1, r - half, c - half); // 좌상+우상+우하귀 더함 (harl*half) * 3
}

int main(void) 
{
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}