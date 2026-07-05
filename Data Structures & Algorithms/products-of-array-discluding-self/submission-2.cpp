class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int res = 1;
        int nzer = 0;
        vector<int> ans;
        for(int i : nums){
            if(i == 0){
                nzer++;
            }
            if(nzer > 1){
                return vector<int>(nums.size(), 0);
            }
            if(i == 0){
                continue;
            }
            res *= i;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                ans.push_back(res);
                continue;
            }
            if(nzer > 0){
                ans.push_back(0);
                continue;
            }
            ans.push_back(res/ nums[i]);
        }
        return ans;

    }
};
