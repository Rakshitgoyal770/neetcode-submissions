class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // unordered_set<int> sat;

        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            int e = nums.size() - 1;
            int s = i + 1;

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            while (e > s) {
                if (s > i + 1 && nums[s] == nums[s - 1]) {
                    s++;
                    continue;
                }
                if (e < nums.size() - 1 && nums[e] == nums[e + 1]) {
                    e--;
                    continue;
                }

                if (t + nums[s] + nums[e] == 0) {
                    ans.push_back({t, nums[s], nums[e]});

                    s++;
                    e--;
                } else if (t + nums[s] + nums[e] > 0) {
                    e--;

                } else {
                    s++;
                }
            }
        }
        return ans;
    }
};