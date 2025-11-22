class BSTIterator {
private:
    // Stack to store nodes
    stack<TreeNode*> myStack; 
    // Flag to determine traversal direction
    bool reverse; 

public:
    // Constructor initializing BSTIterator with the
    // root of the BST and traversal direction
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        // Initialize the stack with nodes
        pushAll(root); 
    }

    // Checks if there exists a
    // next element in the BST
    bool hasNext() {
        // Returns true if the
        // stack is not empty
        return !myStack.empty(); 
    }

    // Retrieves the next smallest element
    // ie. inorder successor in the BST
    int next() {
        // Retrieve the top node from the stack
        TreeNode* tmpNode = myStack.top(); 
         // Remove the top node from the stack
        myStack.pop();
        if (!reverse) {
            // If not in reverse mode,
            // add nodes from the right subtree
            pushAll(tmpNode->right); 
        } else {
            // If in reverse mode,
            // add nodes from the left subtree
            pushAll(tmpNode->left); 
        }
        // Return the value of the retrieved node
        return tmpNode->val; 
    }

private:
    // Helper function to push nodes into
    // the stack in a specific order
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            // Push the node onto the stack
            myStack.push(node); 
            if (reverse) {
                // Move to the right child
                // if in reverse mode
                node = node->right; 
            } else {
                // Move to the left child
                // if not in reverse mode
                node = node->left;
            }
        }
    }
};

// Solution class for performing
// operations on the BST
class Solution {
public:
    // Function to find if there exists
    // a pair with a given sum in the BST
    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            // If the root is empty,
            // return false
            return false; 
        }

        // Initialize two BSTIterators for
        // traversal in different directions
        
        // Left iterator
        BSTIterator l(root, false); 
         // Right iterator
        BSTIterator r(root, true);
        
        // Get the next element from the left iterator
        int i = l.next(); 
        // Get the next element from the right iterator
        int j = r.next(); 

        // Loop to find the pair with the given sum
        while (i < j) {
            if (i + j == k) {
                // If the sum is found,
                // return true
                return true; 
            } else if (i + j < k) {
                // Move to the next element
                // from the left iterator
                i = l.next(); 
            } else {
                // Move to the next element
                // from the right iterator
                j = r.next();
            }
        }
        // If no pair found, return false
        return false; 
    }
};