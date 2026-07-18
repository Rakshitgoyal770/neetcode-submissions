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
    int Sol(TreeNode* root, int& maxi){
        if (root == nullptr){
            return 0;
        }
        int l = Sol(root -> left, maxi);
        int r = Sol(root -> right, maxi);
        maxi = max(maxi, l + r );
        return max(l , r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        Sol(root, maxi);
        return maxi;
        
    }
};
