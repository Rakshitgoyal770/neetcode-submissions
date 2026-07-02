class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> sets;

        for(int i = 0; i < nums.size(); i++){
            if(sets.find(nums[i]) != sets.end()){
                return true;
            }
            else{
                sets.insert(nums[i]);
            }
        }
        return false;
    }
};