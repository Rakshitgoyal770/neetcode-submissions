class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // using the bucket sort
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> buc(n +1);
        vector <int> ans;

        for(int i : nums){
            mp[i] ++;
        }

        for(auto i : mp){
            buc[i.second].push_back(i.first);
        }

        for(int i = n ; i >= 0; i--){
            int temp = buc[i].size();
            if(temp == 0) continue;
            for(int j = 0; j < temp; j++){
                if(k > 0){
                    ans.push_back(buc[i][j]);
                    k --;
                }
                else{
                    return ans;
                }
            }
        }

        return ans;
    }
};
