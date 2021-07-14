class Solution {
public:
    string customSortString(string order, string str) {
        string ans="";
        if(order.length()==0)
            return str;
        sort(str.begin(),str.end());
        for(int i=0;i<order.size();i++){
            for(int j=0;j<str.size();j++){
                if(order[i]==str[j]){
                    ans+=str[j];
                    str.erase(str.begin()+j);
                    j--;
                }
            }
        }
        ans+=str;
        return ans;
    }
};
