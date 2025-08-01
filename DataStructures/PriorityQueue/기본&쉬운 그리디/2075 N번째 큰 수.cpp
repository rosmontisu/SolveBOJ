#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heap[2000];
int sz = 0;

void push(int x)
{
    sz++;
    heap[sz] = x;

    int cur = sz;
    while (cur > 1 && heap[cur / 2] > heap[cur]) {
        swap(heap[cur / 2], heap[cur]);
        cur /= 2;
    }
}

void pop()
{
    if (sz == 0) return;


    heap[1] = heap[sz]; // 마지막 원소를 root로 옮김
    sz--;

    int cur = 1;
    while (cur * 2 <= sz)
    {
        int lc = cur * 2;
        int rc = cur * 2 + 1;
        int maxC = lc;

        if (rc <= sz && heap[lc] > heap[rc])
            maxC = rc;

        // 현재 노드가 자식 노드보다 크거나 같으면 break
        if (heap[cur] <= heap[maxC])
            break;

        // 현재 노드와 자식 노드를 교환
        swap(heap[cur], heap[maxC]);
        cur = maxC;
    }
}

int top()
{
    // 최대 힙의 root가 가장 큰 원소
    return heap[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // n x n 행렬 입력
    for (int i = 0; i < n * n; i++)
    {
        int input;
        cin >> input;
        push(input); // 입력을 힙에 삽입
        if (sz > n) pop(); // 힙의 크기가 n을 초과하면 가장 작은 원소를 삭제
    }

    cout << top() << '\n'; // 가장 큰 원소 출력

    return 0;
}