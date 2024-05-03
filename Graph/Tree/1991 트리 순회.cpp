#include <iostream>

using namespace std;

/*
Binary Tree에서의 Tree Traversal 문제입니다.
직접 preorder/inorder/postorder를 구현해봅시다.
*/

int lc[28];
int rc[28];

void preorder(int cur) {
    // 본인 -> 좌측 -> 우측
    // 이때 본인을 방문(출력)할때는 다시 char형에 맞는 데이터로 바꿔줍니다.
    cout << char(cur + 'A' - 1);
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << char(cur + 'A' - 1);
    if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
    if (lc[cur] != 0) postorder(lc[cur]);
    if (rc[cur] != 0) postorder(rc[cur]);
    cout << char(cur + 'A' - 1);
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char cur, left, right;
        cin >> cur >> left >> right;

        // cur는 아스키로 최소 65(A) 이므로 바로 배열에 넣기에는 부적합합니다.
        // 고로 cur - 65(A) + 1로 { A:1, B:2, C:3, ... } 와 같은 식으로 
        // 값을 보정시켜서 트리를 만들어줍니다.
        // 또한, 트리는 왼쪽에서 오른쪽으로, 위에서 아래로 
        // Z자 모양으로 1씩 증가하는 배열을 생각하면서 구현합니다.
        if (left != '.') lc[cur - 'A' + 1] = (left - 'A' + 1);
        if (right != '.') rc[cur - 'A' + 1] = (right - 'A' + 1);
    }

    preorder(1); cout << '\n';
    inorder(1); cout << '\n';
    postorder(1); cout << '\n';
    return 0;
}