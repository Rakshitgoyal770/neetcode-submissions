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
        for(int x : s){
            if(s.find(x-1) == s.end()){
                int temp = 1;
                int curr = x;
                while(s.find(curr + 1) != s.end()){
                    temp++;
                    curr++;
                }

                ans = max(ans, temp);

            }
        }
        return ans;
        
    }
};