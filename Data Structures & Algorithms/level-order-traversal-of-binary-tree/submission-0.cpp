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
        if(root == nullptr){
            vector<vector<int>> v;
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr); 
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> vac;
            while(q.front() != nullptr){
                TreeNode* temp = q.front();
                q.pop();
                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
                vac.push_back(temp -> val);
            }
            q.pop();
            ans.push_back(vac);
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        return ans;
        
    }
};
