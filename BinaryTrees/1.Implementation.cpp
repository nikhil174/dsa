#include<iostream>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void preOrder(TreeNode* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    preOrder(root);
    return 0;
}