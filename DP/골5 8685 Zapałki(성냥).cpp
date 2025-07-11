/*
문제 제목: 성냥 (Zapałki)


문제 설명
자스(Jaś)는 n개의 성냥을 일렬로 나란히 세웠습니다. 모든 성냥은 머리가 위를 향하도록 세워져 있습니다. 각각의 성냥은 저마다 다른 높이 h_i를 가지고 있습니다.
자스는 성냥 하나에 불을 붙일 수 있습니다. 불이 붙은 성냥은 타들어가면서 높이가 점차 줄어듭니다. 성냥이 타는 동안, 불이 다른 성냥으로 옮겨붙을 수 있습니다. 불이 옮겨붙는 현상은, 타고 있는 성냥의 불꽃 높이가 바로 옆(인접한) 성냥의 머리 높이와 같아지는 순간에 항상 발생합니다.
자스는 처음에 어떤 성냥에 불을 붙여야 가장 많은 수의 성냥을 태울 수 있는지 알고 싶어합니다.

입력
표준 입력의 첫 번째 줄에는 성냥의 개수를 나타내는 정수 n (1 ≤ n ≤ 1,000,000)이 주어집니다.
두 번째 줄에는 n개의 정수 h₁, h₂, ..., hₙ (1 ≤ hᵢ ≤ 1,000,000,000)이 공백으로 구분되어 주어집니다. 여기서 hᵢ는 i번째 성냥의 높이를 의미합니다.

출력
표준 출력의 첫 번째 줄에, 불에 탈 수 있는 성냥의 최대 개수를 정수로 출력해야 합니다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> h(n, -1);
    while (n--)
    {
        int x;
        cin >> x;
        h.push_back(x);
    }




}