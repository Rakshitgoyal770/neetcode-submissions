class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> maps;
        if(s.size() != t.size()){
            return false;
        }

        int arr[26];

        for(int i = 0; i < s.size() ; i++){
            arr[s[i] - '0']++;
        }
        for(int i = 0; i < s.size() ; i++){
            if(arr[t[i] - '0']){
                arr[t[i] - '0']--;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};
