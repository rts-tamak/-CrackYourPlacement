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
    int ans = 0;
    void dfs(TreeNode* root, int val)
    {
        if(!root) return;
        if(val == 0 && root -> left == NULL && root -> right == NULL) ans += root -> val;
        dfs(root -> left, 0);
        dfs(root -> right, 1);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, -1);
        return ans;
    }
};