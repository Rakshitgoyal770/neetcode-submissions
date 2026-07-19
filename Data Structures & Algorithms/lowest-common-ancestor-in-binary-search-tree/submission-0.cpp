class Solution {
public:
    bool Sol(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (root == nullptr)
            return false;

        bool left = Sol(root->left, p, q, ans);
        bool right = Sol(root->right, p, q, ans);

        bool self = (root == p || root == q);

        if ((left && right) ||
            (self && left) ||
            (self && right))
        {
            ans = root;
        }

        return left || right || self;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        Sol(root, p, q, ans);
        return ans;
    }
};
