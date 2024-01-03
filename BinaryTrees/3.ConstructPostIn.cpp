/* https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */

// TC = O(N) , SC = O(N)
class Solution {
private: 
        TreeNode* constructFromPreIn(vector<int> &inorder, vector<int> &postorder, int &postIndex, int inStart, int inEnd, unordered_map <int, int> &mp, int n) {
    if (postIndex < 0 || inStart > inEnd)
        return NULL;

        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];

        root->right = constructFromPreIn(inorder, postorder, postIndex, position + 1, inEnd, mp, n);
        root->left = constructFromPreIn(inorder, postorder, postIndex, inStart, position - 1, mp, n);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map <int, int> mp;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        int postIndex = n - 1;

        return constructFromPreIn(inorder, postorder, postIndex, 0, n - 1, mp, n);
    }
};