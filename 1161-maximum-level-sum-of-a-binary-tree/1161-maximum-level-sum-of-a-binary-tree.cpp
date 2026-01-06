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
    int maxLevelSum(TreeNode* root) {
        int level = 1, min_level = 1, sum = 0, max_sum = INT_MIN;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                TreeNode* front = q.front();
                q.pop();

                sum += front->val;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            if(sum > max_sum) {
                max_sum = sum;
                min_level = level;
            }
            level++;
            sum = 0;
        }
        return min_level;
    }
};