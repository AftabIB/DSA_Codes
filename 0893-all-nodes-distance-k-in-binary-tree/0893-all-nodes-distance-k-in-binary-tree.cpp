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
private:
    std::unordered_map<TreeNode*, TreeNode*> parent;

    void preorder(TreeNode* curr, TreeNode* root) {
        if (!curr) return;
        parent[curr] = root;
        preorder(curr->left, curr);
        preorder(curr->right, curr);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || !target)
            return {};

        preorder(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int level = 0;
        while (!q.empty() && level <= k) {
            int size = q.size();
            vector<int> ans;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (level == k)
                    ans.push_back(curr->val);

                if (curr->left && visited.find(curr->left) == visited.end()) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if (parent[curr] && visited.find(parent[curr]) == visited.end()) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }

            level++;

            if (level > k)
                return ans;
        }

        return {};  // Return an empty vector if k was greater than the tree depth.
    }
};