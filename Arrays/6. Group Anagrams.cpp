// Question Link --> https://leetcode.com/problems/group-anagrams/



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> ump;
        for(auto it : strs){
            auto temp = it;
            sort(temp.begin(),temp.end());
            ump[temp].push_back(it);
        }
        for(auto it : ump)
            ans.push_back(it.second);
        return ans;
    }
};