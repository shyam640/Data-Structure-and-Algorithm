// Question Link --> https://leetcode.com/problems/largest-rectangle-in-histogram/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int i=0,ans=0;
        stack<int> st;
        while(i<heights.size()){
            if(st.empty() or heights[i]>=heights[st.top()]) st.push(i++);
            else{
                int cur=st.top();
                st.pop();
                if(st.empty()) ans = max(ans,heights[cur]*i);
                else ans = max(ans, heights[cur]*(i-st.top()-1));
            }
        }
        return ans;
    }
};
