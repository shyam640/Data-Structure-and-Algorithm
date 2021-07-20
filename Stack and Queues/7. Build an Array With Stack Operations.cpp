// Question Link --> https://leetcode.com/problems/build-an-array-with-stack-operations/


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        int index=0;
        vector<string> ans;
        
        for(int i=1;i<=n;i++)
        {
            st.push(i);
            ans.push_back("Push");
            
            if(st.top()==target[index])
            {
                index++;
            }
            
            else if(st.top()!=target[index])
            {
                ans.push_back("Pop");
                st.pop();
            }
            
            if(target.size()==index)
            {
                break;
            }
                
        }
        
        return ans;   
    }
};