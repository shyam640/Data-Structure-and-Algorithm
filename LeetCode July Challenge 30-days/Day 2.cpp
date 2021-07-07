class Solution {
public:
    int breakPoint(vector<int> arr, int low, int high, int x){
        if(arr[high]<=x)
            return high;
        if(arr[low]>x)
            return low;
        int mid = (low+high)/2;
        // cout<<mid<<endl;
        if(arr[mid]<=x and arr[mid+1]>x)
            return mid;
        if(arr[mid]>x)
            return breakPoint(arr,low,mid-1,x);
        else
            return breakPoint(arr,mid+1,high,x);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = breakPoint(arr,0,arr.size()-1,x);
        int right = left+1;
        // cout<<left<<" "<<right<<endl;
        int count=0;
        vector<int> ans;
        while(count<k and left>=0 and right<arr.size()){
            if((x-arr[left])<=(arr[right]-x) and arr[left]<arr[right])
                ans.push_back(arr[left--]);
            else
                ans.push_back(arr[right++]);
            count++;
        }
        while(count<k and left>=0){
            ans.push_back(arr[left--]);
            count++;
        }
        while(count<k and right<arr.size()){
            ans.push_back(arr[right++]);
            count++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};