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
    pair<int, int> checkRoot(TreeNode* root, int& ans) {
        if(!root) return {0, 0};

        pair<int, int> left = checkRoot(root->left, ans);
        pair<int, int> right = checkRoot(root->right, ans);

        int average = (left.second + right.second + root->val) / (left.first + right.first + 1);

        if(average == root->val) ans++;

        return {left.first + right.first + 1, left.second + right.second + root->val};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        pair<int, int> values = checkRoot(root, ans);
        return ans;
    }
};