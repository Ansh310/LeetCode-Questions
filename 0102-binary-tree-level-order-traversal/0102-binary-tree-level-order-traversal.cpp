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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            while(size--) {

                TreeNode* currNode = q.front();
                q.pop();
                temp.push_back(currNode->val);

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};