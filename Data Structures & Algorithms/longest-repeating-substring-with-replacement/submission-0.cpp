class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map< char, int> mp;
        int l = 0;
        int max_value = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            max_value = max(max_value, mp[s[i]]);
            while((i - l +1) - max_value > k){
                mp[s[l]] --;
                l++;
            }
            ans = max(ans, i - l + 1);
            
        }
        return ans;
        
    }
};
