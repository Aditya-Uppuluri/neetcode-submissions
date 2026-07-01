class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        unordered_map<char,char>matching;
        matching['('] = ')';
        matching['['] = ']';
        matching['{'] = '}';

        stack<char>st;
        for(int i=0; i<len; i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                st.push(s[i]);
            }
            else if(!st.empty() && matching[st.top()]==s[i]) {
                st.pop();
            }
            else return false;
        }
        if(st.empty()) return true;
        return false;
    }
};
