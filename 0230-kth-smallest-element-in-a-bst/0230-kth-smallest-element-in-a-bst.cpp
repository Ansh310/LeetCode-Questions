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
    int findKthSmallest(TreeNode* root, int& k) {
        if(!root) return -1;
        
        int val1 = findKthSmallest(root->left, k);

        k--;
        if(k == 0) val1 = root->val;

        int val2 = findKthSmallest(root->right, k);

        return max(val1, val2);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = findKthSmallest(root, k);
        return ans;
    }
};