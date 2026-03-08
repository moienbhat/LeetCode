/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inorderTraversalHelper(TreeNode* root, vector<int>& result) {
        if (!root) return;

        // Left
        inorderTraversalHelper(root->left, result);

        // Root
        result.push_back(root->val);

        // Right
        inorderTraversalHelper(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalHelper(root, result);
        return result;
    }
};
