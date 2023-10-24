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
int findPosition(vector<int> inorder, int element) {
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == element) {
            return i;
        }
    }
    return -1;
}


TreeNode *solve(vector<int> inorder, vector<int> preorder, int &index, int inorderStart, int inOrderEnd) {
    if (index >= preorder.size() || inorderStart > inOrderEnd) {
        return NULL;
    }

    int element = preorder[index++];
    TreeNode *root = new TreeNode(element);

    int position = findPosition(inorder, element);

    // Recursive call for left
    root->left = solve(inorder, preorder, index, inorderStart, position - 1);

    // Recursive call for right
    root->right = solve(inorder, preorder, index, position + 1, inOrderEnd);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        TreeNode *ans = solve(inorder, preorder, preOrderIndex, 0, inorder.size() - 1);
        return ans;
    }
};