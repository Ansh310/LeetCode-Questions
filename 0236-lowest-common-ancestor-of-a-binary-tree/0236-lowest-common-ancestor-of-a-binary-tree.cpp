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
    TreeNode* solveLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        if(root == p || root == q) return root;

        TreeNode* left = solveLCA(root->left, p, q);
        TreeNode* right = solveLCA(root->right, p, q);

        if(left && right) return root;
        if(left && !right) return left;
        if(!left && right) return right;

        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solveLCA(root, p, q);
    }
};