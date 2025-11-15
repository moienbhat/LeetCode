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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};

        unordered_map<TreeNode*, TreeNode*> parentMap;
        mapParentNodes(root, parentMap);

        return bfsFromTarget(target, parentMap, k);
    }

private:
    // Step 1: Create a map to store each node's parent
    void mapParentNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    // Step 2: BFS starting from target to find all nodes at distance k
    vector<int> bfsFromTarget(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap, int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currentLevel == k) break;

            currentLevel++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Visit left child
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                // Visit right child
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                // Visit parent
                if (parentMap.count(node) && !visited.count(parentMap[node])) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};
