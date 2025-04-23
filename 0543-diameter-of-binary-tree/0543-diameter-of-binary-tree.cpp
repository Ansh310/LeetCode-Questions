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
    int helper_function(TreeNode* root, int &ans) {
        if(!root) return 0;

        int LeftSubtreeDepth = helper_function(root->left, ans);
        int rightSubtreeDepth = helper_function(root->right, ans);

        ans = max(ans, LeftSubtreeDepth + rightSubtreeDepth);
        return max(LeftSubtreeDepth, rightSubtreeDepth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper_function(root, ans);
        return ans;
    }
};