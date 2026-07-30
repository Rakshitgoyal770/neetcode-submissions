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
    TreeNode* Solve(vector<int>& preorder, vector<int>& inorder, int& ri ,int ll, int rr){
        if(ll > rr){
            return nullptr;
        }
        TreeNode* root = new TreeNode;
        root -> val = preorder[ri];
        int temp = -1;
        for (int i = ll; i <= rr; i++){
            if(preorder[ri] == inorder[i]){
                temp = i;
            }
        }
        ri++;
        root -> left = Solve(preorder, inorder, ri, ll, temp - 1);
        root -> right = Solve(preorder, inorder, ri, temp + 1, rr);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rr = preorder.size()-1;
        int ri = 0;
        
        return Solve(preorder, inorder, ri , 0, rr);
    }
};
