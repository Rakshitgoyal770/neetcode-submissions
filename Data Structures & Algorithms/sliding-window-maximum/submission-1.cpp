class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        unordered_map<int, int> mp;

        // Find maximum of first window
        int temp = INT_MIN;
        for (int i = 0; i < k; i++) {
            temp = max(temp, nums[i]);
            mp[nums[i]]++;
        }


        ans.push_back(temp);

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            mp[nums[i]]++;

            mp[nums[i - k]]--;

            if (mp[nums[i-k]] == 0)
                mp.erase(nums[i-k]);
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
                for (auto j : mp) {
                    if(j.first > temp){
                        temp = j.first;
                    }
                } 
            }

            // Otherwise maximum remains unchanged

            ans.push_back(temp);
        }

        return ans;
    }
};