#include <bits/stdc++.h>
using namespace std;
struct treeNode{
    treeNode *left;
    treeNode *right;
    char val;
    treeNode(char c): val(c), left(NULL), right(NULL){};
};
treeNode *head;
treeNode *buildTree(treeNode *h){
    char c;
    cin >> c;
    if(c != '#'){
        h = new treeNode(c);
        h->left = buildTree(h->left), h->right = buildTree(h->right);
    }
    else
        h = NULL;
    return h;
}
void inOrder(treeNode *h){
    if(!h){
        return;
    }
    inOrder(h->left);
    cout << h->val;
    inOrder(h->right);
}
void swapNode(treeNode *h){
    if(h){
        swap(h->left, h->right);
        swapNode(h->left), swapNode(h->right);
    }
    else
        return;
}
int main(){
    head = buildTree(head);
    inOrder(head);
    swapNode(head);
    cout << endl;
    inOrder(head);
    return 0;
}