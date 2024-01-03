/* https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/ */

// TC = O(N) , SC = O(N)
class Solution {
private:
    TreeNode* constructFromPreIn(vector<int> &inorder, vector<int> &preorder, int &preIndex, int inStart, int inEnd, unordered_map <int, int> &mp, int n) {
    if (preIndex >= n || inStart > inEnd)
        return NULL;

        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];

        root->left = constructFromPreIn(inorder, preorder, preIndex, inStart, position - 1, mp, n);
        root->right = constructFromPreIn(inorder, preorder, preIndex, position + 1, inEnd, mp, n);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map <int, int> mp;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        int preIndex = 0;

        return constructFromPreIn(inorder, preorder, preIndex, 0, n - 1, mp, n);
    }
};