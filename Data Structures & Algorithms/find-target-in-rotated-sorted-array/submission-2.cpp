class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()- 1;

        while(e >= s){
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[s]){ //left portion
                if(nums[mid] < target || nums[s] > target ){
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }
            else {
               if(nums[mid] > target || nums[e] < target ){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }

        }
        return -1;
        
    }
};
