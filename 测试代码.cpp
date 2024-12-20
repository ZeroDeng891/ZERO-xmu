#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// 根据前序序列构建二叉树
TreeNode* buildTree(const string& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == '#') {
        index++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[index++]);
    node->left = buildTree(preorder, index);
    node->right = buildTree(preorder, index);
    return node;
}

// 中序遍历二叉树
void inorderTraversal(TreeNode* root, string& result) {
    if (!root) return;
    inorderTraversal(root->left, result);
    result += root->val;
    inorderTraversal(root->right, result);
}

// 交换二叉树中每个节点的左右子树
void swapChildren(TreeNode* root) {
    if (!root) return;
    swap(root->left, root->right);
    swapChildren(root->left);
    swapChildren(root->right);
}

int main() {
    string preorder;
    cin >> preorder;

    // 构建原始二叉树
    int index = 0;
    TreeNode* root = buildTree(preorder, index);

    // 获取原始二叉树的中序遍历序列
    string inorderOriginal;
    inorderTraversal(root, inorderOriginal);

    // 交换每个节点的左右子树
    swapChildren(root);

    // 获取交换后二叉树的中序遍历序列
    string inorderSwapped;
    inorderTraversal(root, inorderSwapped);

    // 输出结果
    cout << inorderOriginal << endl;
    cout << inorderSwapped << endl;

    return 0;
}
