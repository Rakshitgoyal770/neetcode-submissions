class Solution {
public:

// approch 1  - simplest
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

            vector<pair<int, int>> p;
            vector<int> ans;
        for (auto i : mp)   
            p.push_back(i);

            sort(p.begin(), p.end(),
             [](auto a, auto b){
                return a.second > b.second;
             });

            for(int i = 0; i < k; i++){
                ans.push_back(p[i].first);
            }
        
        return ans;
    }
    
};