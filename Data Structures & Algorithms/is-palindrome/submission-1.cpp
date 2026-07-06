class Solution {
public:
    bool isPalindrome(string s) {
        // 2 possibilites - odd/even
        int ed = s.size() - 1;
        int st = 0;

        while(ed >  st){
            if( !(s[st] >= 'a' && s[st] <= 'z') && !(s[st] >= 'A' && s[st] <= 'Z') && !(s[st] >= '0' && s[st] <= '9')){
                st++;
                continue;
            }
            if( !(s[ed] >= 'a' && s[ed] <= 'z') && !(s[ed] >= 'A' && s[ed] <= 'Z') && !(s[ed] >= '0' && s[ed] <= '9')){
                ed --;
                continue;
            }
            if(tolower(s[ed]) == tolower(s[st])){
                ed --;
                st ++;
            }
            else{
                return false;
            }

        }
        return true;
        
    }
};
