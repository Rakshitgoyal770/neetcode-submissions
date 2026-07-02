class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        vector<int> ans(2);

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end() && mp[target - nums[i]] != i){
                ans[0] = i;
                ans[1] = mp[target - nums[i]];
                  return ans;
            }
        }
        
    }
};
