class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        
        inOrderTraversal(root, prev, ans);
        
        return ans;
    }

private:
    void inOrderTraversal(TreeNode* node, int& prev, int& ans) {
        if (node == nullptr) return;
        
        // Traverse the left subtree
        inOrderTraversal(node->left, prev, ans);
        
        // Process the current node
        if (prev != -1) {
            ans = min(ans, node->val - prev);
        }
        prev = node->val;
        
        // Traverse the right subtree
        inOrderTraversal(node->right, prev, ans);
    }
};
