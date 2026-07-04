class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            vector<int> arr(26);
            string key = "";
            for (char c : strs[i]) {
                arr[c - 'a']++;
            }           
            for(int x: arr){
                    key += '#';
                    key += to_string(x);
            }
            mp[key].push_back(strs[i]);
        }


        for(auto &it : mp){
           ans.push_back(it.second);
        }

        return ans;
    }
};