class Solution {
public:
    void generateGreyCodes(vector<int>& ans, int n,int& temp){
        if(n==0){
            ans.push_back(temp);
            return;
        }
        generateGreyCodes(ans,n-1,temp);
        temp = temp^(1<<(n-1));
        generateGreyCodes(ans,n-1,temp);
    }
    vector<int> grayCode(int n) {
        vector<int> ans;
        int temp=0;
        generateGreyCodes(ans,n,temp);
        return ans;
    }
};
