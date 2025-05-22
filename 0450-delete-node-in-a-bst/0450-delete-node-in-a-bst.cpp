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
    TreeNode* getInorderSuccessor(TreeNode* root) {
        TreeNode* ptr = root->right;
        while(ptr->left) {
            ptr = ptr->left;
        }
        return ptr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            TreeNode* temp;
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }
            else if(root->left && !root->right) {
                temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left && root->right) {
                temp = root->right;
                delete root;
                return temp;
            }
            else {
                TreeNode* inorderSuccessor = getInorderSuccessor(root);
                swap(root->val, inorderSuccessor->val);
                root->right = deleteNode(root->right, key);
            }

        }
        return root;
    }
};