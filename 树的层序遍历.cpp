#include <bits/stdc++.h>
using namespace std;
struct treeNode{
    treeNode *left;
    treeNode *right;
    int val;
    treeNode(int x): val(x){};
};
treeNode* buildtree(int hou[], int zhong[], int l1, int r1, int l2, int r2){
    if(l1 >= r1 || l2 >= r2)
        return NULL;
    int root = hou[r1 - 1];
    int i;
    for(i = l2; i < r2; i ++){
        if(zhong[i] == root)
            break;
    }
    treeNode *node = new treeNode(root);
    node->left = buildtree(hou, zhong, l1, l1 + i - l2, l2, l2 + i);
    node->right = buildtree(hou, zhong, l1 + i - l2, r1 - 1, i + 1, r2);
    return node;
}
int main(){ 
    int n;
    cin >> n;
    int postOrder[n], inOrder[n];
    for(int i = 0; i < n; i ++)
        cin >> postOrder[i];
    for(int i = 0; i < n; i ++)
        cin >> inOrder[i];
    treeNode *root = buildtree(postOrder, inOrder, 0, n, 0, n);
    queue<treeNode*> q;
    q.push(root);
    bool first = true;
    while(!q.empty()){
        treeNode* tmp = q.front();
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
        q.pop();
        if(first){
            cout << tmp->val;
            first = false;
        }
        else 
            cout << ' ' <<  tmp->val;
    }
    return 0;
}