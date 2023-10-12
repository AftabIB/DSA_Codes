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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        unordered_map<string,int> m;
        vector<TreeNode*> ans;
        solve(root,m,ans);
        return ans;
    }
string solve(TreeNode* root,unordered_map<string,int> &m,vector<TreeNode*> &ans)
{
        if(!root)
        {
            return "";
        }

        string s = to_string(root->val) + "," + solve(root->left,m,ans) + "," + solve(root->right,m,ans);
        m[s]++;
        if(m[s] == 2)
        {
            ans.push_back(root);
        }
        return s;
    }
};