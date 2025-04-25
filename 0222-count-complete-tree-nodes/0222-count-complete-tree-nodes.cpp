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
    int LH(TreeNode* root) {
        int levels = 0;

        while(root) {
            root = root->left;
            levels++;
        }
        return levels;
    }

    int RH(TreeNode* root) {
        int levels = 0;

        while(root) {
            root = root->right;
            levels++;
        }
        return levels;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftHeight = LH(root);
        int rightHeight = RH(root);

        if(leftHeight == rightHeight) return pow(2, leftHeight) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};