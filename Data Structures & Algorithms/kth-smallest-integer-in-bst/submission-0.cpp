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
    int count = 0;
    int val = 0;
    void Solve(TreeNode* root, int k){
        if(root == nullptr){
            return;
        }
        Solve(root -> left, k);

        count++;
        if(count == k){
            val = root -> val;
        }

        Solve(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        Solve(root, k);
        return val;
        
    }
};
