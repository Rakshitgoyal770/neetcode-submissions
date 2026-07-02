class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> maps;
        if(s.size() != t.size()){
            return false;
        }

        int arr[26];

        for(int i = 0; i < s.size(); i++){
            if(maps.find(s[i]) != maps.end()){
                maps[s[i]]++;
            }
            else{
                maps[s[i]] = 1;
            }
        }
        for(int i = 0; i < s.size() ; i++){
            if(maps.find(t[i]) != maps.end() && maps[t[i]] > 0){
                maps[t[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};
