class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> forward(n);
        vector<int> backward(n);
        vector<int> ans(n);

        forward[0] = nums[0];
        for (int i = 1; i < n; i++) {
            forward[i] = forward[i - 1] * nums[i];
        }

        backward[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            backward[i] = backward[i + 1] * nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (i == 0)
                ans[i] = backward[1];
            else if (i == n - 1)
                ans[i] = forward[n - 2];
            else
                ans[i] = forward[i - 1] * backward[i + 1];
        }

        return ans;
    }
};
