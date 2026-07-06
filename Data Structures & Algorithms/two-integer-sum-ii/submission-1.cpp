class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0;
        int e = numbers.size() -1;
        vector<int> ans(2, 0);
        while(s < e){
            int t = numbers[s] + numbers[e];
            if(t == target){
                ans[0] = s + 1;
                ans[1] = e + 1;
                return ans;
            }
            else if(t >  target)
            {
                e --;
            }
            else{
                s++;
            }

        }
        return ans;
        
    }
};
