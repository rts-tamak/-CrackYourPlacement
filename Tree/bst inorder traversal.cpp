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
vector<int> inorder;
    void dfs(TreeNode* root)
    {
        if(root == NULL) return;
        if(root -> left) dfs(root -> left);
        inorder.push_back(root -> val);
        if(root -> right) dfs(root -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return inorder;
    }
};