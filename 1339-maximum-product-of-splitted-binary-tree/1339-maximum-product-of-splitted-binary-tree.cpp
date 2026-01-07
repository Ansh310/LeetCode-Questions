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
    int dfs(TreeNode*root) {
        if(!root) return 0;
        int curr_sum = dfs(root->left) + dfs(root->right) + root->val;
        
        return curr_sum;
    }

    int f(TreeNode* root, int sum, long long& ans, int total_sum) {
        if(!root) return 0;

        int left = f(root->left, sum, ans, total_sum);
        int right = f(root->right, sum, ans, total_sum);
        sum += left + right + root->val;

        ans = max(ans, (long long)(total_sum - sum) * sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        //calculate total sum using dfs
        //then use post order traversal for ans calculation
        int total_sum = 0;
        total_sum = dfs(root);

        long long ans = 0; int sum = 0;

        f(root, sum, ans, total_sum);

        return ans % (int)(1e9 + 7);
    }
};