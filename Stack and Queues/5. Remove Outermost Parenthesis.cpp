// Question Link --> https://leetcode.com/problems/remove-outermost-parentheses/


class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='(') count++;
            else if(s[i]==')') count--;
            if(count<0){
                count=0;
                i++;
            }else ans+=s[i];
        }
        return ans;
    }
};