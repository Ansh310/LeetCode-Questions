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
    void buildMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* prev) {
        if(!root) return;

        if(prev) parentMap[root] = prev;
        else parentMap[root] = NULL;

        buildMap(root->left, parentMap, root);
        buildMap(root->right, parentMap, root);

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        unordered_set<TreeNode*> vis;

        buildMap(root, parentMap, NULL);

        queue<TreeNode*> q;
        q.push(target); int level = 0;

        while(!q.empty() && level < k) {
            int size = q.size();

            while(size--) {
                TreeNode* front = q.front();
                q.pop();

                vis.insert(front);

                if(front->left && vis.find(front->left) == vis.end()) q.push(front->left);
                if(front->right && vis.find(front->right) == vis.end()) q.push(front->right);

                if(vis.find(parentMap[front]) == vis.end() && parentMap[front]) q.push(parentMap[front]);
            }
            level++;
        }

        vector<int> ans;
        while(!q.empty()) {ans.push_back(q.front()->val); q.pop();}
        return ans;
    }
};