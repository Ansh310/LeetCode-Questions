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
    TreeNode* find_root(vector<vector<int>>& descriptions, unordered_map<int, vector<TreeNode*>>& mapping, int n) {
        for(int i = 0; i < n; i++) {
            TreeNode* Parent, *Child;

            if(mapping.find(descriptions[i][0]) == mapping.end()) {
                
                Parent = new TreeNode(descriptions[i][0]);
                mapping[descriptions[i][0]] = {Parent, NULL};
            }

            else {Parent = mapping[descriptions[i][0]][0];}

            

            if(mapping.find(descriptions[i][1]) == mapping.end()) {
                
                Child = new TreeNode(descriptions[i][1]);
            }

            else {Child = mapping[descriptions[i][1]][0];}

            mapping[descriptions[i][1]] = {Child, Parent};
            
            

            if(descriptions[i][2]) Parent->left = Child;

            else Parent->right = Child;


        }

        TreeNode* ans = NULL;

        for(auto e : mapping) {
            
            if(e.second[1] == NULL) ans = e.second[0];
        }

        return ans;

    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, vector<TreeNode*>> mapping;
        return find_root(descriptions, mapping, n);
    }
};