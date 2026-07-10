class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;

        // Find maximum of first window
        int temp = INT_MIN;
        for (int i = 0; i < k; i++) {
            temp = max(temp, nums[i]);
        }

        ans.push_back(temp);

        // Slide the window
        for (int i = k; i < nums.size(); i++) {

            // Element leaving the window
            int outgoing = nums[i - k];

            // Case 1: New element is greater than current maximum
            if (nums[i] > temp) {
                temp = nums[i];
            }

            // Case 2: Current maximum left the window
            else if (outgoing == temp) {

                temp = INT_MIN;

                // Recompute maximum in current window
                for (int j = i - k + 1; j <= i; j++) {
                    temp = max(temp, nums[j]);
                }
            }

            // Otherwise maximum remains unchanged

            ans.push_back(temp);
        }

        return ans;
    }
};