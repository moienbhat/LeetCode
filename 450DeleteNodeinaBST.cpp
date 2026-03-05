class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Node found
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else {
                // Node with two children: find inorder successor
                TreeNode* successor = findMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
};
