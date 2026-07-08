class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26, 0);
        int l = 0;
        int max_value = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            mp[s[i] - 'A']++;
            max_value = max(max_value, mp[s[i]-  'A']);
            while((i - l +1) - max_value > k){
                mp[s[l] - 'A'] --;
                l++;
            }
            ans = max(ans, i - l + 1);
            
        }
        return ans;
        
    }
};
