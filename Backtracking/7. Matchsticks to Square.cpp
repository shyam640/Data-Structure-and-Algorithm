// Question Link --> https://leetcode.com/problems/matchsticks-to-square/



class Solution {
public:
    bool checkSides(int idx,vector<int>& sides_len_sum,long long int oneSideLength,vector<int>& matchsticks){
        if(idx>=matchsticks.size())
            return (sides_len_sum[0]==sides_len_sum[1] and sides_len_sum[1]==sides_len_sum[2] and sides_len_sum[2]==oneSideLength);
        for(int i=0;i<4;i++){
            if(sides_len_sum[i]+matchsticks[idx]>oneSideLength) continue;
            sides_len_sum[i]+=matchsticks[idx];
            if(checkSides(idx+1,sides_len_sum,oneSideLength,matchsticks)) return true;
            sides_len_sum[i]-=matchsticks[idx];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<=3)
            return false;
        long long int total_len = 0;
        for(int i=0;i<matchsticks.size();i++)
            total_len+=matchsticks[i];
        if(total_len%4) return false;           // If remainder exists then return false
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<int> sides_len_sum(4);
        return checkSides(0,sides_len_sum,total_len/4,matchsticks);
    }
};