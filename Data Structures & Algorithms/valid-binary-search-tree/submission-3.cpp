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
    bool Solve(TreeNode* root, int left, int right){
        if(root == nullptr){
            return true;
        }
        if(Solve(root -> left, left, root -> val) && Solve(root -> right, root -> val, right)){
            if(root -> val > left && root -> val < right){
                return true;
            }
            else{
                return false;
            }
        }
        else {
            return false;
        }
        
        
    }
    bool isValidBST(TreeNode* root) {
        return Solve(root, INT_MIN, INT_MAX);
        
    }
};
