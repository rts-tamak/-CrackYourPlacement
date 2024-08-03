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
    bool check(TreeNode* root, int curr, int targetSum)
    {
        if(root == NULL) return false;
        curr += root -> val;
        if(root-> left == NULL && root -> right == NULL)
        {
            // cout << curr << '\n';
            if(curr == targetSum) return true;
            else return false;
        }

        
        if(root -> left != NULL)
        {
            if(check(root -> left, curr, targetSum))  return true;
        }
        if(root -> right != NULL)
        {
            if(check(root -> right, curr, targetSum)) return true;
        }
        curr -= root -> val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, 0, targetSum);
    }
};