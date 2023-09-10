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
private:
    TreeNode* present(TreeNode* root, int k)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(root->val == k)
        {
            return root;
        }
        if(k>root->val)
        {
            return present(root->right,k);
        }
        else
        {
            return present(root->left,k);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            return new TreeNode(val);
        }
        if(val == root->val)
        {
            return root;
        }
        if(val>root->val)
        {
            root -> right = insertIntoBST(root->right,val);
        }
        else
        {
            root -> left = insertIntoBST(root->left,val);
        }
        return root;
    }
};