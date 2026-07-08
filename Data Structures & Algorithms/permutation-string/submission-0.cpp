class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp(26, 0);
        vector<int> mp2(26, 0);

        for(int i = 0; i < s1.size(); i++){
            mp[s1[i] - 'a']++;
        }


        int left = 0;
        for(int i = 0; i < s2.size(); i++){
            mp2[s2[i] - 'a']++;
            if(i - left + 1 > s1.size()){
                mp2[s2[left] - 'a']--; 
                left++;
            }
            if(mp == mp2){
                return true;
            }
        }
        return false;
    }
};
