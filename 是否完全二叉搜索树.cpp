#include <bits/stdc++.h>
using namespace std;
struct Tree{
    Tree *left;
    Tree *right;
    int val;
    Tree(int x): val(x), left(NULL), right(NULL){};
};
Tree *head;
Tree* insert(int num, Tree *h){
    if(h == NULL) return new Tree(num);
    if(num > h->val){
        h->left = insert(num, h->left);
    }
    else{
        h->right = insert(num, h->right);
    }
    return h;
}
bool isComplete(Tree* h){
    if(h == NULL) return true;
    queue<Tree*> q;
    q.push(h);
    bool isNull = false;
    while(!q.empty()){
        Tree *t = q.front();
        q.pop();
        if(t->left){
            if(isNull) return false;
            q.push(t->left);
        }
        else{
            isNull = true;
        }
        if(t->right){
            if(isNull) return false;
            q.push(t->right);
        }
        else{
            isNull = true;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int num;
        cin >> num;
        head = insert(num, head);
    }
    queue<Tree*> q;
    q.push(head);
    bool first = true;
    while(!q.empty()){
        Tree* t = q.front(); q.pop();
        if(first) {
            cout << t->val;
            first = false;
        }
        else
            cout << ' ' << t->val;
        if(t->left != NULL) q.push(t->left);
        if(t->right != NULL) q.push(t->right);
    }
    cout << endl;
    if(isComplete(head)) cout << "YES";
    else cout << "NO";
    return 0;
}