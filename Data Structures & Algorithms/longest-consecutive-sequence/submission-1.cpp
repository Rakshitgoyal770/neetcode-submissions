class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        sort(nums.begin(), nums.end());
        int ans = 1;
        int temp = 0;
        if (nums.size() == 0){
            return 0;
        }
            
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                temp = 1;
                ans = max(ans , temp);
                continue;
            }
            if(nums[i] == nums[i-1] + 1){
                temp++;
                ans = max(ans , temp);
                continue;
            }
            if( nums[i] == nums[i -1]){
                continue;
            }
            else{
                ans = max(ans , temp);
                temp = 1;
            }
            ans = max(ans , temp);
        }
        return ans;

        
    }
};
