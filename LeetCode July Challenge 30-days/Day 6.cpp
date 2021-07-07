class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int mx = *max_element(arr.begin(),arr.end());
        vector<int> temp(mx+1);
        for(int i=0;i<arr.size();i++)
            temp[arr[i]]++;
        vector<int> freq;
        for(int i=0;i<temp.size();i++){
            if(temp[i])
                freq.push_back(temp[i]);
        }
        sort(freq.rbegin(),freq.rend());
        int count=0,ans=0;
        for(int i=0;i<freq.size();i++){
            count+=freq[i];
            ans++;
            if(count>=arr.size()/2)
                break;
        }
        return ans;
    }
};