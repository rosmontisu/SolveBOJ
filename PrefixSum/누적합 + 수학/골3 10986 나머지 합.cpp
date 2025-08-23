#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> s(n + 1, 0);
    vector<long long> cnt(m + 1, 0);
    for (int i = 1; i <= n; i++) 
    {
        int x; cin >> x;
        s[i] = s[i - 1] + x;
        cnt[s[i] % m]++; // 같은 나머지 카운팅
    }

    long long ans = cnt[0]; // 자기 자신이 이미 나누어지는 경우 (길이 1짜리 구간합)

    for (int i = 0; i < m; i++)
        ans += cnt[i] * (cnt[i] - 1) / 2; // 같은 나머지끼리 구간합 맞추기 (2개씩)

    cout << ans;

    return 0;
}

    // 1. 모듈러 성질
    // (s[j] - s[i-1]) % m == 0 라면
    // s[j] % m == s[i-1] % m 이고

    // 2. 즉 m으로 나누었을 때 같은 나머지가 나오는 누적합 2개를 고르면
    // 그 사이 구간합은 무조건 m으로 나누어 떨어짐

    // 3. 고로, 같은 나머지를 가진 누적합의 개수를 카운트
    // 그 중에서 2개를 고르는 조합(nC2 = n(n-1)/2) 을 모두 더하면 됨 - n < m 까지 전부
    
    // 예외
    // m으로 나누어 떨어지는 경우에는 구간합의 길이가 1이면 충분 (자기 자신만으로 조건 충족)
    // 그러므로, cnt[0]은 바로 더해주면 됨
