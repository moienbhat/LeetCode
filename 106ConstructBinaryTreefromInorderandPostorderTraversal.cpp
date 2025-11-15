/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }

        // Create a map to store the indices
        // of elements in the inorder traversal
        map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }

        // Call the recursive function
        // to build the binary tree
        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
            postorder.size() - 1, hm);
    }

    // Recursive function to build a binary
    // tree from inorder and postorder traversals
    TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie,
        vector<int>& postorder, int ps, int pe, map<int, int>& hm) {

        // Base case: If the subtree
        // is empty, return NULL
        if (ps > pe || is > ie) {
            return NULL;
        }

        // Create a new TreeNode
        // with the root value from postorder
        TreeNode* root = new TreeNode(postorder[pe]);

        // Find the index of the root
        // value in inorder traversal
        int inRoot = hm[postorder[pe]];
        
        // Number of nodes in the left subtree
        int numsLeft = inRoot - is; 

        // Recursively build the
        // left and right subtrees
        root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder,
            ps, ps + numsLeft - 1, hm);

        root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder,
            ps + numsLeft, pe - 1, hm);

        // Return the root of
        // the constructed subtree
        return root;
    }
};