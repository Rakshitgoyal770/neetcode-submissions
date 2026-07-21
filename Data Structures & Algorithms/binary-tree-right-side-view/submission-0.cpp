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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode* >q;
        q.push(root);
        q.push(nullptr);
        vector<int> ans;
        while(!q.empty()){
            TreeNode* temp;
            while(q.front() != nullptr){
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                    
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                    temp = q.front();
                    q.pop();
            }
            ans.push_back(temp -> val);
            q.pop();  
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        return ans;
    }
};
