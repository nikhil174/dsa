
// TC - O(n), SC = o(n)
bool isLeaf(TreeNode* root) {
    return root->left == nullptr && root->right == nullptr;
}

void addLeft(TreeNode* root, vector<int>& ans) {
    TreeNode* curr = root;
    while (curr!= nullptr) {
        if (!isLeaf(curr)) ans.push_back(curr->val);
        if (curr->left != nullptr) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeaf(TreeNode* root, vector<int>& ans) {
    if (isLeaf(root)) {
        ans.push_back(root->val);
    }

    if (root->left != nullptr) addLeaf(root->left, ans);
    if (root->right != nullptr) addLeaf(root->right, ans);
}

void addRight(TreeNode* root, vector<int>& ans) {
    TreeNode* curr = root;
    vector<int> temp;
    while (curr != nullptr) {
        if (!isLeaf(curr)) temp.push_back(curr->val);

        if (curr->right != nullptr) curr = curr->right;
        else curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
        ans.push_back(temp[i]);
}

vector<int> binaryTreeBoundaryTraversal(TreeNode* root) {
    vector<int> ans;

    if (root == nullptr) return ans;
    if (!isLeaf(root)) ans.push_back(root->val);
    addLeft(root->left, ans);
    addLeaf(root, ans);
    addRight(root->right, ans);

    return ans;
}