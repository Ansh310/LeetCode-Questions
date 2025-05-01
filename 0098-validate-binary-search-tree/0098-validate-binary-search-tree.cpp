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
    #define ll long long int
    bool checkBST(TreeNode* root, ll lb, ll ub) {
        if(!root) return true;

        return root->val > lb && root->val < ub && checkBST(root->left, lb, root->val) && checkBST(root->right, root->val, ub);
    }
    bool isValidBST(TreeNode* root) {
        ll lb = (ll)INT_MIN - 1;
        ll ub = (ll)INT_MAX + 1;

        return checkBST(root, lb, ub);
    }
};