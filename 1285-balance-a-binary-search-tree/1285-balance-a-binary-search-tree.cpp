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

TreeNode* buildTree(vector<int> &v,int start,int end)
{
    //base case
    if(start > end) return NULL;
    //find the mid
    int mid = (start + end)/2;
    //create the new node and insert it into vector of mid
    TreeNode* root = new TreeNode(v[mid]);
    //recursive call of left tree
    root->left = buildTree(v,start,mid-1);
    //recursive call of right tree
    root->right = buildTree(v,mid+1,end);
    //return the root 
    return root;
}

void inorder(TreeNode* root,vector<int> &v)
{
    if(!root)
        return;
    
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        TreeNode* ans = buildTree(v,0,v.size()-1);
        return ans;
    }
};