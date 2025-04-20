/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solveLCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if(!root) return false;

        bool presentLeft = solveLCA(root->left, p, q, ans);
        bool presentRight = solveLCA(root->right, p, q, ans);

      if((presentRight && presentLeft) || (root == p || root == q)) {ans = root; return true;}
        if(presentRight || presentLeft) return true;

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        solveLCA(root, p, q, ans);
        return ans;
    }
};