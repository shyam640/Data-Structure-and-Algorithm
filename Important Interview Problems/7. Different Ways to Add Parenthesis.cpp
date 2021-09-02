// Question Link --> https://leetcode.com/problems/different-ways-to-add-parentheses/


class Solution {
public:
    unordered_map<string,vector<int>> umap;
    vector<int> diffWaysToCompute(string expression) {
        if(umap.count(expression)) return umap[expression];
        vector<int> ans;
        for(int i=0;i<expression.length();i++){
            if(expression[i]=='+' or expression[i]=='-' or expression[i]=='*'){
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(auto &j : left){
                    for(auto &k : right){
                        if(expression[i]=='+') ans.push_back(j+k);
                        if(expression[i]=='-') ans.push_back(j-k);
                        if(expression[i]=='*') ans.push_back(j*k);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return umap[expression] = ans;
    }
};