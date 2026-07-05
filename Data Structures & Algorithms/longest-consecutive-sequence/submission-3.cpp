class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int min = INT_MAX;
        int maxi = INT_MIN;
        if(nums.size() == 0) return 0;
        for(int i : nums){
            if(i <= min){
                min = i;
            }
            if(i >= maxi){
                maxi = i;
            }

            if(s.find(i) != s.end()){
                continue;
            }
            else{
                s.insert(i);
            }
            
        }
        int ans = 1;
        int temp = 1;
        for(int i = min; i <= maxi; i++){
            if(i == maxi){
                return ans;
            }
            if(s.find(i) != s.end()  && s.find(i+1) != s.end()){
                temp++;
                ans = max(ans, temp);
            }
            else{
                temp = 1;
            }
            ans = max(ans, temp);

        }
        return ans;
        
    }
};
