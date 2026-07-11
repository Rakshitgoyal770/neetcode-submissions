class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                if((s[i] == ')' || s[i] == '}' || s[i] == ']')){
                    return false;
                }
                st.push(s[i]);
                continue;
            }
            

            char temp = st.top();

            if( (temp == '{' && s[i] == '}') || (temp == '[' && s[i] == ']') || (temp == '(' && s[i] == ')') ){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        if(st.empty()){
            return true;
        }
        return false;
        
    }
};
