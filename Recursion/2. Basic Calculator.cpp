// Question Link --> https://leetcode.com/problems/basic-calculator/



class Solution {
public:
    int calculate(string s) {
        // Method 1 --> Using Built in function eval() for string expressions in python
        // return eval(s);
        
        // Method 2 --> Using stack
        int ans=0;
        stack<int> st;
        int sign=1;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                int val=0;
                while(isdigit(s[i])){
                    val = val*10 + (s[i]-'0');
                    i++;
                }
                i--;
                ans+=(sign*val);
                sign = 1;
            }else if(s[i]=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                sign=1;
            }else if(s[i]==')'){
                ans = ans*st.top();
                st.pop();
                ans = ans+st.top();
                st.pop();
            }else if(s[i]=='-')
                sign = -1;
        }
        return ans;
    }
};