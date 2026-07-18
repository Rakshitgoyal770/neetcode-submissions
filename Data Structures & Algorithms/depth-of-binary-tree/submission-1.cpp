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
    int solution(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = solution(root -> left);
        int r = solution(root -> right);
        return max(l, r) + 1;
    }

    int maxDepth(TreeNode* root) {
        return solution(root);
        
    }
};
