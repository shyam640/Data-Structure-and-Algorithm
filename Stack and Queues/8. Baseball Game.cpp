// Question Link --> https://leetcode.com/problems/baseball-game/


class Solution {
public:
    bool is_number(const std::string &s) {
        if(s[0]=='-')
            return !s.empty() && std::all_of(s.begin()+1, s.end(), ::isdigit);
        else
          return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }
    int calPoints(vector<string>& ops) {
        int res=0;
        vector<int> ans;
        for(int i=0;i<ops.size();i++){
            if(is_number(ops[i])){
                ans.push_back(stoi(ops[i]));
            }else if(ops[i]=="+" and ans.size()>=2){
                ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]);
            }else if(ops[i]=="C"){
                ans.resize(ans.size()-1);
            }else if(ops[i]=="D"){
                ans.push_back(2*ans[ans.size()-1]);
            }
        }
        for(int i=0;i<ans.size();i++)
            res+=ans[i];
        return res;
    }
};