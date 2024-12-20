#include <bits/stdc++.h>
using namespace std;
typedef struct _node{
    int val;
    _node *left;
    _node *right;
    _node(int x): val(x), left(NULL), right(NULL) {};
}treeNode;

treeNode *insert(treeNode *root, int x){
    if(!root){
        return new treeNode(x);
    }
    if(x < root->val) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

bool isSame(treeNode *r1, treeNode *r2){
    if(!r1 && !r2) return true;
    if(r1 == NULL || r2 == NULL)
        return false;
    return (r1->val == r2->val) && isSame(r1->left, r2->left) && isSame(r1->right, r2->right);
}

int main(){
    while(true){
        int n, l;
        cin >> n;
        if(n == 0) break;
        cin >> l;
        treeNode *root = NULL;
        for(int i = 0; i < n; i ++){
            int num;
            cin >> num;
            root = insert(root, num);
        }
        while(l --){
            treeNode *rt = NULL;
            for(int i = 0; i < n; i ++){
                int num;
                cin >> num;
                rt = insert(rt, num);
            }
            if(isSame(root, rt))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}