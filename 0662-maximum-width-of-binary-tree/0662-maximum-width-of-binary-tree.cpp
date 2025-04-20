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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        long maxdist = 0;

        while(!q.empty()) {
            long size = q.size();
            long first = q.front().second;
            long last = q.back().second;
            maxdist = max(maxdist, last - first + 1);
            int low = q.front().second;

            while(size--) {
                auto front = q.front();
                long curr = q.front().second - low;
                q.pop();
                

                if(front.first->left) q.push({front.first->left, 2 * curr + 1});
                if(front.first->right) q.push({front.first->right, 2 * curr + 2});

            }
        }
        return maxdist;
    }
};