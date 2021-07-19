// Question Link --> https://leetcode.com/problems/simplify-path/


class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> arr;
        while(ss.good()){
            string substr;
            getline(ss,substr,'/');
            arr.push_back(substr);
        }
        stack<string> st;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==".."){
                if(st.empty())
                    continue;
                st.pop();
            }else if(arr[i]=="" or arr[i]==".")
                continue;
            else
                st.push(arr[i]);
        }
        string ans="";
        while(!st.empty()){
            ans = '/'+st.top()+ans;
            st.pop();
        }
        if(ans=="")
            return "/";
        return ans;
    }
};