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

        for (int i = 0; i < s.size(); i++) {

            mp2[s[i]]++;

            while (true) {

                bool ok = true;

                for (auto j : mp1) {
                    if (mp2[j.first] < mp1[j.first]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok)
                    break;

                int len = i - left + 1;

                if (len < diff) {
                    diff = len;
                    ans_left = left;
                }

                mp2[s[left]]--;
                left++;
            }
        }

        if (ans_left == -1)
            return "";

        return s.substr(ans_left, diff);
    }
};
