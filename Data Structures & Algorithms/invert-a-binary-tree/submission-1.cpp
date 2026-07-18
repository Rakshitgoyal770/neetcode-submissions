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

    TreeNode* result(TreeNode* root){
        if( root == nullptr){
            return nullptr;
        }
        if(root -> left == nullptr && root -> right == nullptr){
            return root;
        }
        else if(root -> left == nullptr && root-> right){
            root -> left = root-> right;
            root -> right = nullptr;
            result(root-> left);
            return root;
        }
        else if(root -> right == nullptr && root-> left){
            root -> right = root-> left;
            root -> left = nullptr;
            result(root-> right);
            return root;
        }
        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        result(root -> left);
        result(root -> right);
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return result(root);
        
    }
};
