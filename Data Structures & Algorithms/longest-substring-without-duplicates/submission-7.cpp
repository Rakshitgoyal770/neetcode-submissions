class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int size = s.size();
        int left = 0;
        int maxi = 1;
        int ans = 1;
        set<int> ss;
        ss.insert(s[0]);
        for(int i = 1; i < size; i++){
            while(ss.find(s[i]) != ss.end()){
                ss.erase(s[left]);
                left ++;
            }
            ss.insert(s[i]);
            maxi = i - left + 1 ;
            ans = max(ans, maxi);

        }
        return ans;
        
     }
};
