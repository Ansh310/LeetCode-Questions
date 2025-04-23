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
    int helper(TreeNode* root, int count) {
        if(!root) return count;
        
        int cntNodesLeft = helper(root->left, count + 1);
        int cntNodesRight = helper(root->right, count + 1);

        return max(cntNodesLeft, cntNodesRight);

    }
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
};