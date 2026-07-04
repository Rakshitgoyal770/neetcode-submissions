class Solution {
public:
    bool valPal(string st1, string st2){
        if(st1.size() != st2.size()){
            return false;
        }
        unordered_map<char, int> mp;

        for(int i = 0 ; i < st1.size(); i++){
            if(mp.find(st1[i]) != mp.end()){
                mp[st1[i]] ++;
            }
            else{
                mp[st1[i]] = 1;
            }
        }
        for(int i = 0 ; i < st1.size(); i++){
            if(mp.find(st2[i]) != mp.end() && mp[st2[i]] > 0){
                mp[st2[i]] --;
            }
            else{
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // first try brute force

        vector<vector<string>> ans;

        set <int> iscomp;


        for(int i = 0; i < strs.size(); i++){
            if(iscomp.find(i) != iscomp.end()){
                continue;
            }

            vector<string> arr;
            arr.push_back(strs[i]);

            for(int j = i+1; j < strs.size(); j++){
                if(valPal(strs[i], strs[j])){
                    arr.push_back(strs[j]);
                    iscomp.insert(j);
                }
            }
            ans.push_back(arr);
        }
        return ans;
    }
};
