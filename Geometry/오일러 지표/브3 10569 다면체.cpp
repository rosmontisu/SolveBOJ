/*
(위상수학 이상엽 복습)
v를 꼭짓점 e를 모서리 f를 면의 수 라고 할때

다면체에서의 오일러 지표 X는 아래와 같다
X = v - e + f

모든 다면체는 구와 위상동형이므로, 다면체의 오일러 지표 X의 값은
그 모양에 관계 없이 항상 2이다.

폐구간 interval : 1
원 circle : 0
원판 disk : 1
구 sphere : 2
torus : 0 - 두 원의 곱공간(product)과 위상동형
*/

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int v, e;
        cin >> v >> e;
        cout << -1 * (v-e-2) << '\n';
    }
}