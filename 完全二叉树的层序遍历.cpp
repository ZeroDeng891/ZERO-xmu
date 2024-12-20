#include <bits/stdc++.h>
using namespace std;

const int maxn = 31;
int n;
int tree[maxn];

void create(int i) {
    if (i > n) return;
    create(2 * i);    // 左子树
    create(2 * i + 1);  // 右子树
    cin >> tree[i];     // 根节点
}

int main() {
    cin >> n;
    create(1);  // 从根节点(下标1)开始构建

    // 层序遍历输出
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << tree[i];
    }
    return 0;
}