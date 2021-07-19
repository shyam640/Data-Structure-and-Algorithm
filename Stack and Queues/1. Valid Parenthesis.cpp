// Question Link --> https://leetcode.com/problems/valid-parentheses/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s[0]==')' or s[0]==']' or s[0]=='}' or s.length()==1)
            return false;
        for(int i=0;i<s.length();i++){
            if(!st.empty() and s[i]==')' and st.top()=='(')
                st.pop();
            else if(!st.empty() and s[i]=='}' and st.top()=='{')
                st.pop();
            else if(!st.empty() and s[i]==']' and st.top()=='[')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};
