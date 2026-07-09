class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for (int i = 0; i < t.size(); i++) {
            mp1[t[i]]++;
        }

        int left = 0;
        int ans_left = -1;
        int diff = INT_MAX;
        int have = 0;
        int req = mp1.size();

        for (int i = 0; i < s.size(); i++) {

            mp2[s[i]]++;

            if (mp1.count(s[i]) && mp2[s[i]] == mp1[s[i]]){
                have++;
                while (have == req) {

                    int len = i - left + 1;

                    if (len < diff) {
                        diff = len;
                        ans_left = left;
                    }

                    mp2[s[left]]--;
                    if(mp1.count(s[left]) && mp2[s[left]] < mp1[s[left]]){
                        have--;
                    }
                    left++;
                }
            }
        }

        if (ans_left == -1)
            return "";

        return s.substr(ans_left, diff);
    }
};
