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
    int checkBalanced(TreeNode* root, bool &ans) {
        if(!root) return 0;
        
        int leftPathLength = checkBalanced(root->left, ans);
        int rightPathLength = checkBalanced(root->right, ans);

        if(abs(leftPathLength - rightPathLength) > 1) ans = false;

        return max(leftPathLength, rightPathLength) + 1;

    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        checkBalanced(root, ans);
        return ans;
    }
};