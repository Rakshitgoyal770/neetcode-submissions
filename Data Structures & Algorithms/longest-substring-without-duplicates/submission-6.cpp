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
            if(ss.find(s[i]) != ss.end()){
                while(ss.find(s[i]) != ss.end()){
                    ss.erase(s[left]);
                    left ++;
                }
                ss.insert(s[i]);

                ans = max(ans, maxi);
                maxi = i - left + 1 ;
            }
            else{
                maxi ++;
                ss.insert(s[i]);
            }
            ans = max(ans, maxi);

        }
        return ans;
        
     }
};
