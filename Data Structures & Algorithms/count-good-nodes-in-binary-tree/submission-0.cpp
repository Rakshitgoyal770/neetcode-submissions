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
    stack<int> mx;

    void Solve(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (mx.empty()) {
            mx.push(root->val);
            count++;
        }
        else if (root->val >= mx.top()) {
            mx.push(root->val);
            count++;
        }
        else {
            mx.push(mx.top());
        }

        Solve(root->left);
        Solve(root->right);

        mx.pop();
    }

    int goodNodes(TreeNode* root) {
        Solve(root);
        return count;
    }
};